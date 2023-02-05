import sys
input = sys.stdin.readline
n = int(input())
A = list(map(int, input().split()))
dp = [1] * (n+1)
for i in range(1, n+1):
    for j in range(1, i):
        if A[i-1] < A[j-1]:
            dp[i] = max(dp[i], dp[j] + 1)
print(max(dp))