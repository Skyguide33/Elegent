from random import shuffle
T = 25
n = 9
print(T)
for _ in range(T):
    print(n)
    
    p = [i for i in range(1, n+1)]
    shuffle(p)
    for i in p:
        print(i, end=' ')
    print()