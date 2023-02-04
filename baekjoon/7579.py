import sys
input = sys.stdin.readline
n, m = map(int, input().split())
memory = list(map(int, input().split()))
cost = list(map(int, input().split()))
c = sum(cost)
dp = [[0] * (c+1) for _ in range(n+1)]
result = c
for i in range(1, n+1):
    mem = memory[i-1]
    cos = cost[i-1]
    for j in range(1, c+1):    
        if j < cos:
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-cos] + mem)

        if dp[i][j] >= m:
            result = min(result, j)

if m != 0:
    print(result)
else:
    print(0)
