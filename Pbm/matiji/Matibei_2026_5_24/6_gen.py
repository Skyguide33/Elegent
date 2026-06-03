from random import randint

T = 500
print(T)

for _ in range(T):
    n = randint(1, 500)
    m = randint(1, 500)
    print(n, m)
    a = [randint(1, 500) for _ in range(n)]
    for _ in range(m):
        l = n; r = 0
        while l > r:
            l = randint(0, n-1)
            r = randint(0, n-1)
        maxn = 0
        for i in range(l, r+1):
            maxn = max(maxn, a[i])
        print(l+1, r+1, maxn)
    
            
    