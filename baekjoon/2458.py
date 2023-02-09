import sys
input = sys.stdin.readline
INF = 1e9
n, m = map(int, input().split())
graph = [[0] * (n+1) for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a][b] = 1

for m in range(1, n+1):
    for s in range(1, n+1):
        for e in range(1, n+1):
            if s==e:
                continue
            if graph[s][e] == 1 or (graph[s][m] == 1 and graph[m][e] == 1):
                graph[s][e] = 1

ans = 0
for i in range(1, n+1):
    cnt = 0
    for j in range(1, n+1):
        cnt += graph[i][j] + graph[j][i]
    if cnt == n-1:
        ans += 1

print(ans)