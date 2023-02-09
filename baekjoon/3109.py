import sys
input = sys.stdin.readline
r, c = map(int, input().split())
arr = []
visited = [[0] * c for _ in range(r)]
for i in range(r):
    v = list(input()[:c])
    arr.append(v)

dx = [1, 1, 1]
dy = [-1, 0, 1]

cnt = 0
def dfs(x, y, paths):

    if x == c-1:
        global cnt
        cnt += 1
        return True

    temp = False

    for i in range(3):
        nx = dx[i] + x
        ny = dy[i] + y
        if 0<=nx<c and 0<=ny<r and visited[ny][nx] == 0 and arr[ny][nx] == '.':
            paths.append((nx, ny))
            visited[ny][nx] = 1
            temp = dfs(nx, ny, paths)
            if not temp:
                paths.pop()
            else:
                return True

    return False

for i in range(r):
    if arr[i][0] == '.':
        dfs(0, i, [(0, i)])

print(cnt)