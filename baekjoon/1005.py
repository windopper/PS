import sys, heapq
from collections import deque, defaultdict
input = sys.stdin.readline
T = int(input())
times = []
for _ in range(T):
    n, k = map(int, input().split())
    d = [0] + list(map(int, input().split()))
    indegree = [0] * (n+1)
    graph = defaultdict(list)
    dist = defaultdict(int)

    for _ in range(k):
        a, b = map(int, input().split())
        graph[a].append(b)
        indegree[b] += 1

    w = int(input())
    max_time = 0
    q = deque()
    for i in range(1, n+1):
        if indegree[i] == 0:
            q.append(i)
            dist[i] = d[i]

    while q:
        node = q.popleft()
        for nxt in graph[node]:
            indegree[nxt] -= 1
            dist[nxt] = max(dist[node] + d[nxt], dist[nxt])
            if indegree[nxt] == 0:
                q.append(nxt)

    print(dist[w])