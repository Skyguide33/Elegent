n = int(input())
c = [0]*(n+1)
c[0] = 1
for i in range(1, n+1):
  for j in range(i):
    c[i] += c[j]*c[i-1-j]
print(c[n])