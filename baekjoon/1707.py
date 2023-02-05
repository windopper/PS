import sys
from collections import defaultdict
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
K = int(input())
for _ in range(K):

    V, E = map(int, input().split())
    graph = defaultdict(list)
    color = {}
    bipartite = True

    for _ in range(E):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)
    
    def dfs(x, c=1):
        global bipartite
        color[x] = c
        for i in graph[x]:
            if i not in color:
                dfs(i, 1-c)
            elif color[i] == c:
                bipartite = False
                return

    for i in range(V):
        if i not in color:
            dfs(i)

    print('YES' if bipartite else 'NO')