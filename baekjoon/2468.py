import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
N = int(input())
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
arr = []
max_height = 0
for i in range(N):
    v = list(map(int, input().split()))
    max_height = max(max_height, max(v))
    arr.append(v)

def dfs(x, y, h, visited):
    visited[y][x] = 1
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0<=nx<N and 0<=ny<N and visited[ny][nx] == 0\
            and arr[ny][nx] > h:
            dfs(nx, ny, h, visited)

safe_zones = []
for h in range(0, max_height):
    cnt = 0
    visited = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if arr[i][j] > h and visited[i][j] == 0:
                dfs(j, i, h, visited)
                cnt += 1
    safe_zones.append(cnt)
print(max(safe_zones))