import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline
h, w = map(int, input().split())

arr = []

for i in range(h):
    arr.append(list(map(int, input().split())))

MAX = max(map(max, arr))

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]
max_sum = 0
visited = [[0] * w for _ in range(h)]
def dfs(x, y, c, total):
    global max_sum
    if total + MAX * (4-c) <= max_sum:
        return
    if c == 4:
        max_sum = max(max_sum, total)
        return

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0<=nx<w and 0<=ny<h and visited[ny][nx] == 0:
            visited[ny][nx] = 1
            dfs(nx, ny, c + 1, total + arr[ny][nx])
            dfs(x, y, c + 1, total + arr[ny][nx])
            visited[ny][nx] = 0

for i in range(h):
    for j in range(w):
        visited[i][j] = 1
        dfs(j, i, 1, arr[i][j])
        visited[i][j] = 0

print(max_sum)
