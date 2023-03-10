import sys
sys.setrecursionlimit(10**5)
from collections import defaultdict
input = sys.stdin.readline
n = int(input())
graph = defaultdict(list)
for i in range(n-1):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

dist = [-1] * (n+1)
dist[1] = 0

def dfs(node, length):
    for nxt_node, nxt_length in graph[node]:
        if dist[nxt_node] == -1:
            dist[nxt_node] = nxt_length + length
            dfs(nxt_node, nxt_length + length)

dfs(1, 0)

deepest = -1
max_dist = max(dist)
for k, v in enumerate(dist):
    if v == max_dist:
        deepest = k
        break

dist = [-1] * (n+1)
dist[deepest] = 0

dfs(deepest, 0)

print(max(dist))

