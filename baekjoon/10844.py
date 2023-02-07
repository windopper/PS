import sys, math
input = sys.stdin.readline
n = int(input())
dp = [0] * (n+3)
dp[1] = 9
dp[2] = 17
for i in range(3, n+1):
    dp[i] = dp[i-1] * 2 - 2 * i // 2
print(dp[n])
