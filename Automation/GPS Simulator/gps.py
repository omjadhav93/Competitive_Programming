import asyncio
import aiohttp
import random
import logging
from datetime import datetime, timedelta, date

API_BASE = "http://localhost:5000/api"
TIME_MULTIPLIER = 60  # 1 real sec = 1 simulated minute
SEMAPHORE = asyncio.Semaphore(200)

# Pick a fixed base simulation date (change this as needed)
BASE_DATE = date(2025, 9, 10)

logging.basicConfig(level=logging.INFO, format="%(asctime)s - %(message)s")

def parse_time(t: str):
    """Convert HH:MM string → timedelta since midnight"""
    h, m = map(int, t.split(":"))
    return timedelta(hours=h, minutes=m)

def interpolate_points(start, end, steps=50):
    lon1, lat1 = start
    lon2, lat2 = end
    return [
        (lon1 + (lon2 - lon1) * i / steps,
         lat1 + (lat2 - lat1) * i / steps)
        for i in range(steps + 1)
    ]

async def simulate_trip(session, trip):
    async with SEMAPHORE:
        bus_id = trip["busId"].get("busNumber") if "busId" in trip else f"SIM{trip['_id'][:6]}"
        logging.info(f"🚍 Starting simulation for {bus_id}")

        # Build station sequence with times
        stations = [trip["startStation"]] + trip.get("stops", []) + [trip["endStation"]]
        times = [parse_time(st["scheduledTime"]) for st in stations]
        coords = [st["coordinates"] for st in stations]

        # Build full path with timestamps (timedelta since midnight)
        path_with_times = []
        for idx in range(len(coords) - 1):
            seg_points = interpolate_points(coords[idx], coords[idx + 1], steps=30)
            seg_duration = times[idx + 1] - times[idx]
            step_delta = seg_duration / len(seg_points)
            for j, (lon, lat) in enumerate(seg_points):
                path_with_times.append((lon, lat, times[idx] + j * step_delta))

        # Stream GPS updates
        current_date = BASE_DATE
        last_minutes = None

        for i, (lon, lat, sim_time) in enumerate(path_with_times):
            minutes = sim_time.total_seconds() / 60

            # Detect crossing midnight → increment date
            if last_minutes is not None and minutes < last_minutes:
                current_date += timedelta(days=1)

            last_minutes = minutes

            fake_datetime = datetime.combine(current_date, datetime.min.time()) + sim_time

            gps_payload = {
                "busId": bus_id,
                "latitude": lat,
                "longitude": lon,
                "speed": round(random.uniform(25, 45), 1),
                "heading": random.randint(0, 359),
                "lastUpdated": fake_datetime.isoformat() + "Z"
            }

            try:
                async with session.post(f"{API_BASE}/gps", json=gps_payload) as resp:
                    logging.info(f"[{bus_id}] Point {i+1}/{len(path_with_times)} "
                                 f"→ {resp.status}, time={gps_payload['lastUpdated']}")
            except Exception as e:
                logging.error(f"[{bus_id}] Error: {e}")

            # Sleep according to simulated time
            if i < len(path_with_times) - 1:
                real_sleep = (path_with_times[i + 1][2] - sim_time).total_seconds() / TIME_MULTIPLIER
                await asyncio.sleep(max(0.01, real_sleep))

async def fetch_trips():
    async with aiohttp.ClientSession() as session:
        async with session.get(f"{API_BASE}/trips") as resp:
            trips = await resp.json()
            return trips.get("data", [])

async def main():
    trips = await fetch_trips()
    async with aiohttp.ClientSession() as session:
        tasks = [simulate_trip(session, trip) for trip in trips]
        await asyncio.gather(*tasks)

if __name__ == "__main__":
    asyncio.run(main())
