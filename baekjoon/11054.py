import sys
input = sys.stdin.readline

n = int(input())
A = list(map(int, input().split()))
dp = [[1 for _ in range(n)] for _ in range(2)] 

for i in range(n):
    for j in range(i):
        if A[i] > A[j]:
            dp[0][i] = max(dp[0][i], dp[0][j] + 1)

A.reverse()
for i in range(n):
    for j in range(i):
        if A[i] > A[j]:
            dp[1][i] = max(dp[1][i], dp[1][j] + 1)

dp[1].reverse()
l = []
for i in range(n):
    l.append(dp[0][i] + dp[1][i])
print(max(l)-1)
