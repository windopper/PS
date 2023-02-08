import sys
sys.setrecursionlimit(10**5)
from collections import defaultdict
input = sys.stdin.readline

V = int(input())

graph = defaultdict(list)

for _ in range(V):
    i = list(map(int, input().split()))[:-1]
    k = i[0]
    del i[0]
    while i:
        d = i.pop()
        to = i.pop()
        graph[k].append((to, d))
        graph[to].append((k, d))

dist = [-1] * (V+1)

def dfs(node, length):
    for nxt_node, nxt_length in graph[node]:
        if dist[nxt_node] == -1:
            dist[nxt_node] = nxt_length + length
            dfs(nxt_node, length + nxt_length)

dist[1] = 0
dfs(1, 0)

deepest = 0
max_dist = max(dist)
for k, v in enumerate(dist):
    if v == max_dist:
        deepest = k
        break

dist = [-1] * (V+1)

dist[deepest] = 0
dfs(deepest, 0)

print(max(dist))
