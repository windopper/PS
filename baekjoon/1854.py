import sys
from collections import defaultdict
import heapq
input = sys.stdin.readline
n, m, k = map(int, input().split())

graph = defaultdict(list)
limit = defaultdict(int)

for i in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    limit[b] += 1

q = [(0, 1)]

dist = [[1e9] * k for _ in range(n+1)]
dist[1][0] = 0

while q:
    time, node = heapq.heappop(q)
    for next_node, next_time in graph[node]:
        alt = next_time + time
        if dist[next_node][k-1] <= alt:
            continue
        dist[next_node][k-1] = alt
        dist[next_node].sort()
        heapq.heappush(q, (alt, next_node))


for j in range(1, n+1):
    if dist[j][k-1] != 1e9:
        print(dist[j][k-1])
    else:
        print(-1)