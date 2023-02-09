"""
벨만포드 알고리즘
"""

import sys
from collections import defaultdict
input = sys.stdin.readline
INF = 1e9
n, m = map(int, input().split())
edges = []
for _ in range(m):
    a, b, c = map(int, input().split())
    edges.append((a, b, c))

dist = [INF] * (n+1)


def bellman_ford(start):
    dist[start] = 0
    # initialize start node
    for i in range(n):
        # check all edges for every iterate
        for j in range(m):
            cur, next, cost = edges[j]
            if dist[cur] != INF and dist[next] > dist[cur] + cost:
                if i == n-1:
                    return True
                # there is negative cycle in graph
                # because we already check and update all nodes
                dist[next] = dist[cur] + cost
    
    return False

has_negative_cycle = bellman_ford(1)

if has_negative_cycle:
    print(-1)
else:
    for i in range(2, n+1):
        if dist[i] == INF:
            print(-1)
        else:
            print(dist[i])