import sys
from collections import defaultdict
import heapq
input = sys.stdin.readline
n, m = map(int, input().split())
graph = defaultdict(list)
for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

dist = defaultdict(int)
paths = [['-'] * (n+1) for _ in range(n+1)]

for i in range(1, n+1):
    dist = defaultdict(int)
    q = [(0, i, None)]
    while q:
        time, node, before = heapq.heappop(q)
        if node in dist:
            continue
        dist[node] = time
        if before is not None:
            paths[i][node] = before
        for next_node, next_time in graph[node]:
            alt = next_time + time
            new_before = before
            if new_before is None:
                new_before = next_node
            heapq.heappush(q, (alt, next_node, new_before))

for i in range(1, n+1):
    for j in range(1, n+1):
        print(paths[i][j], end=' ')
    print()

