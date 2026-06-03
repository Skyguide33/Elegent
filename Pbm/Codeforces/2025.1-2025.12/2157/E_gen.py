from random import randint
T = 10
n = 10
print(T)
for _ in range(T):
    print(n, randint(1, n))
    for _ in range(n):
        print(randint(1, n+1), end=' ')
    print()
