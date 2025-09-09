for _ in range(int(input())):
    n = int(input())
    ans = []
    for i in range(1,18):
        if n % ((10**i)+1) == 0:
            ans.append(n // ((10**i)+1))
    ans.sort()
    print(len(ans))
    if len(ans) > 0: print(*ans)