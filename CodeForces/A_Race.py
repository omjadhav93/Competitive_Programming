for _ in range(int(input())):
    a, x, y = map(int, input().split())
    x, y = min(x, y), max(x, y)
    if x <= a <= y:
        print("NO")
        continue
    if a < x or a > y:
        print("YES")
        continue