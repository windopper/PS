import sys
from collections import defaultdict
input = sys.stdin.readline
N, M = map(int, input().split())
graph = defaultdict(list)
for i in range(M):
    s, e = map(int, input().split())
    graph[s].append(e)
    graph[e].append(s)

visited = []
def dfs(x):
    visited.append(x)
    for i in graph[x]:
        if i in visited:
            continue
        dfs(i)

cnt = 0
for i in range(1, N+1):
    if i not in visited:
        cnt += 1
        dfs(i)

print(cnt)