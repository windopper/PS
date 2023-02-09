import sys
input = sys.stdin.readline
INF = -1e9
n, start, end, m = map(int, input().split())
edges = []

money = [INF] * n

for _ in range(m):
    s, e, c = map(int, input().split())
    edges.append((s, e, -c))

earn = list(map(int, input().split()))
cycle_nodes = set([])

def fn():
    money[start] = earn[start]
    for i in range(n):
        for s, e, c in edges:
            if money[s] != INF and money[e] < money[s] + c + earn[e]:
                money[e] = money[s] + c + earn[e]
                if i == n-1:
                    cycle_nodes.add(e)

for s, e, c in edges:
    if money[s] != INF and money[e] < money[s] + c + earn[e]:
        cycle_nodes.add(e)      

fn()
result = money[end]
if result == INF:
    print('gg')
elif end in cycle_nodes:
    print('Gee')
else:
    print(result)
