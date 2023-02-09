import sys
input = sys.stdin.readline
INF = 1e9
tc = int(input())
edges = []
for _ in range(tc):
    n, m ,w = map(int, input().split())
    for _ in range(m):
        s, e, t = map(int, input().split())
        edges.append((s, e, t))
        edges.append((e, s, t))
    for _ in range(w):
        s, e, t = map(int, input().split())
        edges.append((s, e, -t))

    def bellman_ford(start, dist):
        dist[start] = 0

        for i in range(n):
            for cur, next, time in edges:
                if dist[cur] != INF and dist[next] > dist[cur] + time:
                    dist[next] = dist[cur] + time

    time_travel_is_possible = False

    for i in range(1, n+1):
        dist = [INF] * (n+1)
        bellman_ford(i, dist)
        if dist[i] < 0:
            time_travel_is_possible = True
            break
    
    print('YES' if time_travel_is_possible else 'NO')
            

