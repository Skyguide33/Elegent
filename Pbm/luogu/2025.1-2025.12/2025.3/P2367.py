# 2025/3/27
[n, p] = [int(i) for i in input().split()]
if n >= 500000: 
    print(1)
    exit()
a = [int(i) for i in input().split()]
b = [0] * (n+1)

for i in range(p):
    [x, y, z] = [int(i) for i in input().split()]
    b[x-1] += z; b[y] -= z
for i in range(1, n):
    b[i] += b[i-1]
for i in range(n):
    a[i] += b[i]
print(min(a))