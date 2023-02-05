import sys
sys.setrecursionlimit(15000)
input = sys.stdin.readline
N = int(input())
arr = [list(input()[:N]) for _ in range(N)]
arr2 = []

for i in arr:
    arr2.append(i[:])

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def dfs(x, y, colors):
    arr[y][x] = 'C'
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0<=nx<N and 0<=ny<N and arr[ny][nx] in colors:
            dfs(nx, ny, colors)

cnt1 = 0
colors = ['R', 'G', 'B']
for i in range(N):
    for j in range(N):
        if arr[i][j] in colors:
            dfs(j, i, [arr[i][j]])
            cnt1 += 1

cnt2 = 0
arr = arr2
for i in range(N):
    for j in range(N):
        if arr[i][j] in ['R', 'G']:
            dfs(j, i, ['R', 'G'])
            cnt2 += 1
        elif arr[i][j] == 'B':
            dfs(j, i, arr[i][j])
            cnt2 += 1  
        
print(cnt1, cnt2, sep='\n')