for _ in range(int(input())):
    n = int(input())
    a = input().strip()
    m = int(input())
    b = input().strip()
    c = input().strip()
    for i in range(m):
        if c[i] == 'D':
            a += b[i]
        else:
            a = b[i] + a
    print(a)