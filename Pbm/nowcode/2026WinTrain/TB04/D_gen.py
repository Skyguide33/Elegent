from random import randint

T = 10000
print(T)
while T:
    a = randint(1, 50000000000)
    s = randint(1, 50000000000)
    c1 = randint(-50000000, 50000000)
    c2 = randint(-50000000, 50000000)
    x = c1*a+c2*s
    if 0 < x <= 1000000000000000000:
        print(x, a, s)
        T -= 1
    