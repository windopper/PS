import sys
input = sys.stdin.readline
n, k = map(int, input().split())
values = [int(input()) for _ in range(n)]
values.sort()
ans = 0
dp = [0] * (k+1)
for v in values:
    dp[v] = 1

for i in range(1, k+1):
    if i in values:
        continue
    temp = i
    cnt = 0
    for v in values:
        if v < temp:
            temp -= v
            cnt += dp[temp]
            print(f'temp{ temp} dp {dp[temp]}')
    print(cnt)
    dp[i] = cnt
print(dp[k])