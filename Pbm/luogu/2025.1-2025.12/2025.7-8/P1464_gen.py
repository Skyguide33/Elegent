from random import randint

n = randint(100000, 100000)

rgen = lambda: randint(-9223372036854775808,9223372036854775807)
for _ in range(n):
    print(rgen(), rgen(), rgen())
print(-1, -1, -1)