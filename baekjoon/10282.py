import sys
from collections import defaultdict
import heapq
input = sys.stdin.readline
T = int(input())
for _ in range(T):
    n, d, c = map(int, input().split())

    graph = defaultdict(list)
    dist = defaultdict(int)

    for _ in range(d):
        a, b, s = map(int, input().split())
        graph[b].append((a, s))

    q = [(0, c)]
    while q:
        time, node = heapq.heappop(q)
        if node in dist:
            continue
        dist[node] = time
        for next_node, next_time in graph[node]:
            alt = time + next_time
            heapq.heappush(q, (alt, next_node))
            
    print(len(dist.items()), max(dist.values()))