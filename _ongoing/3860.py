import sys
from collections import deque
input = sys.stdin.readline
INF = 1e9
dx = [0, 0, 1, -1]
dy = [-1, 1, 0, 0]

while True:
    w, h = map(int, input().split())
    if w==0 and h==0:
        break

    start = (0, 0)
    end = (w-1, h-1)
    visited = [[0] * w for _ in range(h)]
    dist = [[INF] * w for _ in range(h)]
    adj = [[[] for _ in range(w)] for _ in range(h)]

    g = int(input())
    gravestones = [[0] * w for _ in range(h)]
    for _ in range(g):
        x, y = map(int, input().split())
        gravestones[y][x] = 1

    e = int(input())
    wormholes = [[0] * w for _ in range(h)]
    for _ in range(e):
        x1, y1, x2, y2, t = map(int, input().split())
        wormholes[y1][x1] = 1
        adj[y1][x1].append((x2, y2, t))

    # 간선 만들어 주기
    for i in range(h):
        for j in range(w):
            if gravestones[i][j] == 1 and wormholes[i][j] == 1:
                continue
            if i == h-1 and j == w-1:
                continue
            for k in range(4):
                nx = x + dx[k]
                ny = y + dy[k]
                if 0<=nx<w and 0<=ny<h:
                    if gravestones[ny][nx] == 1:
                        continue
                    adj[i][j].append((nx, ny, 1))

    
    def bellman_ford():
        dist[0][0] = 0

        for l in range(w*h-g):
            for i in range(h):
                for j in range(w):
                    if gravestones[i][j] == 1:
                        continue
                    if dist[i][j] == INF:
                        continue

                    for x, y, t in adj[i][j]:
                        if dist[y][x] > dist[i][j] + t:
                            if l == w*h-g-1:
                                return True
                            dist[y][x] = dist[i][j] + t

        return False

    has_cycle = bellman_ford()
    result = dist[h-1][w-1]
    if result == INF:
        print('Impossible')
    elif has_cycle:
        print('Never')
    else:
        print(result) 
    