from random import randint
T = 10
n = 10
print(T)
for _ in range(T):
    print(n)
    for _ in range(n):
        print(randint(1, 4), end=' ')
    print()