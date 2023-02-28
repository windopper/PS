import sys
input = sys.stdin.readline
N, L = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort(reverse=True)
l = 0
cnt = 0
while arr:
    target = arr.pop()
    if target + 0.5 > l:
        l = target - 0.5 + L
        cnt += 1

print(cnt)
