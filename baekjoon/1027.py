import sys
input = sys.stdin.readline
n = int(input())
arr = list(map(int, input().split()))
dp = [0] * (n+1)
total = 0
for i in range(0, n):
    cnt = 0
    for j in range(0, n):
        if i == j:
            continue
        m = (arr[i] - arr[j]) / (i - j)
        b = arr[i] - m * i
        can_see = True
        if i > j:
            for k in range(i-1, j, -1):
                y = m * k + b
                if arr[k] >= y:
                    can_see = False
                    break
        else:
            for k in range(i+1, j):
                y = m * k + b
                if arr[k] >= y:
                    can_see = False
                    break

        if can_see:
            cnt += 1

    total = max(total, cnt)

print(total)