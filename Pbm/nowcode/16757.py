# 2026/2/4
n, k = [int(ch) for ch in input().split(' ')]
s = ' '+input()

dp = [[0]*41 for _ in range(7)]

slen = len(s)
for i in range(1, slen):
    dp[0][i] = int(s[:i+1])
    # print(dp[0][i], end=' ')
# print()
    
for i in range(1, k+1):
    for j in range(1, slen):
        for l in range(1, j):
            dp[i][j] = max(dp[i][j], dp[i-1][l]*int(s[l+1:j+1]))

print(dp[k][slen-1])