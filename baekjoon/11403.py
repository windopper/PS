import sys
input = sys.stdin.readline
n = int(input())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))
for m in range(n):
    for s in range(n):
        for e in range(n):
            if arr[s][e] == 0 and arr[s][m] == 1 and arr[m][e] == 1:
                arr[s][e] = 1

for i in range(n):
    print(*arr[i], sep=' ', end='\n')
        