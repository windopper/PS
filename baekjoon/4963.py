"""
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

dx = [0, 0, -1, 1, 1, -1, 1, -1]
dy = [1, -1, 0, 0, -1, 1, 1, -1]

islands = []
while True:
    w, h = map(int, input().split())
    if w == 0 and h == 0:
        break
    arr = []
    for i in range(h):
        arr.append(list(map(int, input().split())))

    def dfs(x, y):
        arr[y][x] = 0
        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0<=nx<w and 0<=ny<h and arr[ny][nx] == 1:
                dfs(nx, ny)

    cnt = 0
    for i in range(h):
        for j in range(w):
            if arr[i][j] == 1:
                dfs(j, i)
                cnt += 1
    islands.append(cnt)

print(*islands, sep='\n')
"""

"""
bfs 풀이
"""
import sys
from collections import deque
input = sys.stdin.readline

dx = [0, 0, -1, 1, 1, -1, 1, -1]
dy = [1, -1, 0, 0, -1, 1, 1, -1]

islands = []
while True:
    w, h = map(int, input().split())
    if w == 0 and h == 0:
        break
    arr = []
    for i in range(h):
        arr.append(list(map(int, input().split())))

    def bfs(x, y):
        q = deque()
        q.append((x, y))
        
        while q:
            x, y = q.popleft()
            arr[y][x] = 0
            for i in range(8):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0<=nx<w and 0<=ny<h and arr[ny][nx] == 1:
                    q.append((nx, ny))

    cnt = 0
    for i in range(h):
        for j in range(w):
            if arr[i][j] == 1:
                bfs(j, i)
                cnt += 1

    islands.append(cnt)
print(*islands, sep='\n')