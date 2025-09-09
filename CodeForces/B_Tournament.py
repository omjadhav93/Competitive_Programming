for _ in range(int(input())):
    n, j, k = map(int, input().split())
    arr = list(map(int, input().split()))
    if k > 1:
        print("YES")
    else:
        if max(arr) == arr[j-1]:
            print("YES")
        else:
            print("NO")