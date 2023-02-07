import sys
from collections import deque
input = sys.stdin.readline
r, c = map(int, input().split())
dist = [[0] * c for _ in range(r)]
arr = []
home = None
q = deque()
for i in range(r):
    v = list(input()[:c])

    for j in range(c):
        if v[j] == 'D':
            home = (j, i)
            continue
        elif v[j] == 'S':
            q.append((j, i))

    arr.append(v)

for i in range(r):
    for j in range(c):
        if arr[i][j] == '*':
            q.append((j, i))

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

def bfs():
    hx, hy = home
    while q:
        x, y = q.popleft()

        if arr[hy][hx] == 'S':
            return dist[hy][hx]
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0<=nx<c and 0<=ny<r:
                if (arr[ny][nx] == '.' or arr[ny][nx] == 'D')\
                    and arr[y][x] == 'S':
                    arr[ny][nx] = 'S'
                    dist[ny][nx] = dist[y][x] + 1
                    q.append((nx, ny))
                elif (arr[ny][nx] == '.' or arr[ny][nx] == 'S')\
                    and arr[y][x] == '*':
                    arr[ny][nx] = '*'
                    q.append((nx, ny))

    return 'KAKTUS'

print(bfs())
