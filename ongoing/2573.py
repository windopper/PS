import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
n, m = map(int, input().split())
arr = []
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]
max_height = 0
for i in range(n):
    v = list(map(int, input().split()))
    max_height = max(max(v), max_height)
    arr.append(v)

def dfs(x, y, visited):
    visited[y][x] = 1
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0<=nx<m and 0<=ny<n and visited[ny][nx] == 0 and arr[ny][nx] > 0:
            dfs(nx, ny, visited)

year = 0
for k in range(0, max_height+1):
    
    visited = [[0] * m for _ in range(n)]
    # check detached
    cnt = 0
    for i in range(n):
        for j in range(m):
            if arr[i][j] > 0 and visited[i][j] == 0:
                dfs(j, i, visited)
                cnt += 1

    if cnt >= 2:
        year = k
        break

    # melt
    melt_list = []
    for i in range(n):
        for j in range(m):
            if arr[i][j] > 0:
                z = 0
                for l in range(4):
                    nx = j + dx[l]
                    ny = i + dy[l]
                    if 0<=nx<m and 0<=ny<n and arr[ny][nx] == 0:
                        z += 1
                melt_list.append((j, i, z))
    
    for i in melt_list:
        x, y, z = i
        if arr[y][x] - z < 0:
            arr[y][x] = 0
        else:
            arr[y][x] -= z

print(year)      