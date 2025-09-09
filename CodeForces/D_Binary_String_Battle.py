for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input().strip()
    if n >= 2*k:
        cnt = 0
        for ch in s:
            if ch == '1':
                cnt += 1
        if cnt > k:
            print("Bob")
        else:
            print("Alice")
    else:
        print("Alice")