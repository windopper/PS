import sys
input = sys.stdin.readline
n = int(input())
A = [0] + list(map(int, input().split()))
dp = [0] * (n+1)
for i in range(1, n+1):
    dp[i] = A[i]
    for j in range(1, i):
        if A[j] < A[i]:
            dp[i] = max(dp[i], dp[j] + A[i])
print(max(dp))

