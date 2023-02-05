a = input()
b = input()
dp = [[0] * (len(b)+1) for _ in range(len(a)+1)]

for i in range(1, len(a)+1):
    for j in range(1, len(b)+1):
        if a[i-1] == b[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j] , dp[i][j-1])

# dp = [0] * len(b)
# for i in range(1, len(a)+1):
#     cnt = 0
#     for j in range(1, len(b)+1):
#         if cnt < dp[j]:
#             cnt = dp[j]
#         elif a[i] == b[j]:
#             dp[j] = cnt + 1


print(dp[len(a)][len(b)])