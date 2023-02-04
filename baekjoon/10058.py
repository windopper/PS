import sys
from collections import defaultdict
import math
input = sys.stdin.readline
n, d = map(int, input().split())
sensor = []
graph = defaultdict(set)

def dist(x1, y1, x2, y2):
    return math.sqrt((x2-x1)**2 + (y2-y1)**2)

for i in range(n):
    x, y = map(int, input().split())
    sensor.append((x, y))
for i, j in enumerate(sensor):
    x1, y1 = j
    for k, l in enumerate(sensor):
        x2, y2 = l
        # if k in graph or k == i:
        #     continue
        if dist(x1, y1, x2, y2) <= d:
            graph[i+1].add(k+1)
            graph[k+1].add(i+1)

print(graph)
"""
selected = [-1] * (n+1)
for i in range(n):
    visited = [False] * (n+1)
    bimatch(i)

def bimatch(i):
    if visited[i]:
        return False
    visited[i] = True
    for n in graph[i]:
        if selected[n] == -1 or bimatch(selected[i]):
            selected[n] = i
            return True"""

for i, v in graph.items():
    for j in v:
        if i == j: continue
        