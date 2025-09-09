for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    cnt = [0] * (n + 1)
    for num in arr:
        cnt[num] += 1
    cntcnt = [0] * (n + 1)
    for num in cnt:
        if num == 0: break
        cntcnt[num] += 1
    end = max(cnt)
    ans = 1
    print(ans, end=' ')
    if n >= 1:
        ans += cntcnt[1]
        if end == 1:
            ans -= 1
        print(ans, end=' ')
    for i in range(2,end + 1):
        if cntcnt[i] > 0:
            ans += cntcnt[i]
        if cntcnt[i] == 1 and i == end:
            ans -= 1
        print(ans, end=' ')
    for i in range(end+1, n + 1):
        if ans > 1:
            ans -= 1
        print(ans, end=' ')
    print()