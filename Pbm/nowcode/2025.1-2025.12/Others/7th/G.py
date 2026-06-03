from math import gcd

MOD = 998244353
t = int(input())
for _ in range(t):
    [a, b, c, d] = [int(i) for i in input().split()]
    print(gcd(a**b, c**d) % MOD)
    
