import sys
input = sys.stdin.readline
N = int(input())
arr = []
for i in range(N):
    arr.append(list(map(int, input()[:N])))

houses = []
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

def dfs(x, y, cnt):
    arr[y][x] = 0
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0<=nx<N and 0<=ny<N and arr[ny][nx] != 0:
            cnt = dfs(nx, ny, cnt + 1)
    return cnt

for i in range(N):
    for j in range(N):
        if arr[i][j] != 0:
            houses.append(dfs(j, i, cnt=1))

houses.sort()
print(len(houses))
print(*houses, sep='\n')