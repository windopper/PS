"""
python3 으로 내면 시간 초과 발생함
pypy3로 내면 재귀 사용시 메모리 사용이 높으므로 recursion limit를 낮춰주는 것이 포인트

"""

import sys
from collections import deque
sys.setrecursionlimit(10**4)
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

def bfs(x, y, visited, melt_list):
    q = deque()
    q.append((x, y))
    while q:
        x, y = q.popleft()
        visited[y][x] = 1
        cnt = 0
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0<=nx<m and 0<=ny<n:
                if arr[ny][nx] == 0:
                    cnt += 1
                elif visited[ny][nx] == 0 and arr[ny][nx] > 0:
                    q.append((nx, ny))

    if cnt != 0:
        melt_list.append((x, y, cnt))

year = 0

while True:
    
    visited = [[0] * m for _ in range(n)]
    melt_list = []
    # check detached
    cnt = 0
    for i in range(n):
        for j in range(m):
            if arr[i][j] > 0 and visited[i][j] == 0:
                cnt += 1
                if cnt >= 2:
                    break
                bfs(j, i, visited, melt_list)

    if cnt >= 2:
        break

    # melt
    """
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
    """
    
    for i in melt_list:
        x, y, z = i
        arr[y][x] -= z
        if arr[y][x] < 0:
            arr[y][x] = 0

    if sum(map(sum, arr[1:-1])) == 0:
        year = 0
        break

    year += 1
            
print(year)      