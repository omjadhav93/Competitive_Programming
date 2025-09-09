def calc(n):
    if n < 3: return n*3
    p, c = 0, 1
    while n >= 3*c: p += 1; c *= 3
    return (3**(p+1))+p*(3**(p-1)) + calc(n-c)

for _ in range(int(input())):
    n = int(input())
    print(calc(n))