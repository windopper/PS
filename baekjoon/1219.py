import sys
from collections import defaultdict
input = sys.stdin.readline
INF = -1e12
n, start, end, m = map(int, input().split())

fees = []
edges = defaultdict(list)

money = [INF] * n

for _ in range(m):
    s, e, c = map(int, input().split())
    fees.append((s, e, c))

earn = list(map(int, input().split()))

for i in fees:
    s, e, c = i
    w = earn[e] - c
    edges[s].append((e, w))

cycle_nodes = []

def fn():
    money[start] = earn[start]
    for i in range(n):
        for s in range(n):
            for e, c in edges[s]:
                if money[s] != INF and money[e] < money[s] + c:
                    money[e] = money[s] + c
                    if i == n-1 and e not in cycle_nodes:
                        cycle_nodes.append(e) 
"""
n-1 번째 탐색을 진행했음에도 업데이트가 된다면 음의 사이클이 존재하다는 뜻
따라서 해당 노드들을 리스트에 저장 한 후
bfs를 통하여 음의 사이클에 영향을 받는 노드들을 검색하여
가중치가 발산하는 노드들을 탐색할 수 있도록 한다.

처음에는 n-1 번째 탐색을 했을 때 업데이트가 된 노드들만 음의 사이클에
영향을 받는 줄 알았지만 음의 사이클에 영향을 받는 노드들을 모두
탐색하는 데 필요한 탐색 횟수는 n-1 보다 크므로 음의 사이클에 1차적으로
영향을 받은 노드들을 저장한 후 bfs 탐색을 통하여 인접한 노드들을
찾아낸다.
"""
def bfs():
    visited = []
    while cycle_nodes:
        cur = cycle_nodes.pop()
        for e, c in edges[cur]:
            if e not in visited:
                visited.append(e)
                cycle_nodes.append(e)
    
    if end in visited:
        return True
    return False


fn()
result = money[end]
if result == INF:
    print("gg")
else:
    if bfs():
        print("Gee")
    else:
        print(result)
