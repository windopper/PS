import sys
input = sys.stdin.readline
n = int(input())
w = list(map(int, input().split()))
w.sort()
total = 1
for i in w:
    if total < i:
        break
    total += i
print(total)