from random import randint

n = randint(4, 15)
m = randint(4, 9)
for _ in range(n):
    tt = randint(0, 2)
    if tt == 0: print('a', end='')
    elif tt == 1: print('b', end='')
    else: print('c', end='')
print()
for _ in range(m):
    tt = randint(0, 2)
    if tt == 0: print('a', end='')
    elif tt == 1: print('b', end='')
    else: print('c', end='')
print()