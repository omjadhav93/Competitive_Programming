for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    pre, suf = [0] * n, [0] * n
    pre[0] = arr[0]
    for i in range(1, n):
        pre[i] = min(pre[i - 1], arr[i])
    suf[n - 1] = arr[n - 1]
    for i in range(n - 2, -1, -1):
        suf[i] = max(suf[i + 1], arr[i])
    ans = ""
    for i in range(n):
        if (pre[i] == arr[i] and suf[i] >= arr[i]) or (suf[i] == arr[i] and pre[i] <= arr[i]):
            ans += "1"
        else:
            ans += "0"
    print(ans)