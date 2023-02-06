import sys
input = sys.stdin.readline
n, k = map(int, input().split())
coins = [int(input()) for _ in range(n)]

dp = [1e9] * (k+1)
dp[0] = 0

for i in range(n):
    for j in range(coins[i], k+1):
        dp[j] = min(dp[j], dp[j-coins[i]] + 1)

ans = dp[-1] if dp[-1] != 1e9 else -1
print(ans)