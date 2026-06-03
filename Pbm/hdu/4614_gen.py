# 2025/9/5
from random import randint

t = 1
print(t)
for _ in range(t):
    n = randint(2, 10)
    m = randint(5, 8)
    print(n, m)
    for _ in range(m):
        k = randint(1, 2)
        if k == 1:
            a = randint(0, n-1)
            b = randint(1, n-1)
        else:
            a = randint(0, n-1)
            b = randint(a, n-1)
        print(k, a, b)

        
        