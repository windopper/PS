# standard problem of using floyd-warshall algorithm
import sys
INF = 1e9
input = sys.stdin.readline
n = int(input())
m = int(input())
dist = [[0] * (n+1) for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, n+1):
        if i==j:
            continue
        dist[i][j] = INF

for i in range(m):
    s, e, d = map(int, input().split())
    dist[s][e] = min(d, dist[s][e])

for m in range(1, n+1):
    for s in range(1, n+1):
        for e in range(1, n+1):
            if dist[s][e] > dist[s][m] + dist[m][e]:
                dist[s][e] = dist[s][m] + dist[m][e]

for i in range(1, n+1):
    for j in range(1, n+1):
        print(0 if dist[i][j] == INF else dist[i][j] , end=' ')
    print()
