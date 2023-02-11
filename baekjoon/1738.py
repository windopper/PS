import sys, math
from collections import defaultdict
input = sys.stdin.readline
INF = -math.inf
adjs = defaultdict(list)
n, m = map(int, input().split())
for _ in range(m):
    u, v, w = map(int, input().split())
    adjs[u].append((v, w))

START = 1
END = n
dist = [INF] * (n+1)
path = [0] * (n+1)
cycle_nodes = []
visited = []

def fn():
    dist[START] = 0

    for i in range(n):
        for u in range(1, n+1):
            if dist[u] == INF:
                continue
            for v ,w in adjs[u]:
                if dist[v] < dist[u] + w:
                    dist[v] = dist[u] + w
                    path[v] = u
                    if i == n-1:
                        if v not in visited:
                            visited.append(v)
                            cycle_nodes.append(v)

def bfs():
    while cycle_nodes:
        u = cycle_nodes.pop()
        for v, w in adjs[u]:
            if v in visited:
                continue
            visited.append(v)
            cycle_nodes.append(v)

    return visited

def make_path():
    cur = END
    result = [END]
    while cur != START:
        result.append(path[cur])
        cur = path[cur]
    return result[::-1]

fn()
bfs()
if END in visited:
    print(-1)
else:
    print(*make_path(), sep=' ')

