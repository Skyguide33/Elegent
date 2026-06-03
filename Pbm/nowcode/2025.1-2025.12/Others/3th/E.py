
from math import *
t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(item) for item in input().split(' ')]
    if n % 2 == 1: print('YES0')
    elif n == 2:
        if a[0] == a[1]: print('YES ')
        else: print('NO1')
    else:
        sum = 1
        for i in range(n):
            sum *= a[i]
    
        ans = 1
        if (sum%a[n-1] != 0): ans = 0
        sum = sum//a[n-1]
        op = floor(sum ** 0.5)
        print("op=", op)
        if op*op != sum: ans = 0
        print("ans=", ans)
        if ans != 0: print('YES2')
        else: print('NO2')
         