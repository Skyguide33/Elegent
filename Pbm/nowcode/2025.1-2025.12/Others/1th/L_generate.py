import random
t = 100
dynamic_nq = False
max_n = 5000 
max_q = 5000
init_max_num = 1000000000
add_max_num = 1000000000
print(t, end='\n')
for _ in range(t):
    if dynamic_nq:
        n = random.randint(1, max_n)
        q = random.randint(1, max_q)
    else: n, q = max_n, max_q
    print(n, q, sep=' ', end='\n')
    for _ in range(n):
        print(random.randint(1, init_max_num), sep=' ', end=' ')
    print()
    for _ in range(q):
        print(random.randint(1, n), random.randint(1, add_max_num), sep=' ', end='\n')

