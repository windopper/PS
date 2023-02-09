import sys
input = sys.stdin.readline
INF = 1e9
tc = int(input())

for _ in range(tc):
    n, m ,w = map(int, input().split())
    dist = [INF] * (n+1)
    edges = []
    for _ in range(m):
        s, e, t = map(int, input().split())
        edges.append((s, e, t))
        edges.append((e, s, t))
    for _ in range(w):
        s, e, t = map(int, input().split())
        edges.append((s, e, -t))

    def bellman_ford(start):

        dist[start] = 0

        for i in range(n):
            for cur, next, time in edges:
                if dist[next] > dist[cur] + time:
                    dist[next] = dist[cur] + time
                    if i == n-1:
                        return True

        return False

    if bellman_ford(1):
        print('YES')
    else:
        print('NO')
    
            

