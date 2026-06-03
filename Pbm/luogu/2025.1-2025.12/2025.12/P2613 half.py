# 2025/11/11

# 拓展欧几里得定理
def exgcd(a, b):
	if (b == 0):
		return 1, 0, a
	x, y, g = exgcd(b, a % b)
	x, y = y, x - a // b * y
	return x, y, g

m = 19260817
a = int(input()); b = int(input())
x, y, d = exgcd(b, a)
if a%d == 0:
  print(x*(a//d)%m)
else:
  print("Angry!")