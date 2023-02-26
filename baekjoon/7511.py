import sys
input = sys.stdin.readline

def find(x):
    if x == parent[x]: return x
    parent[x] = find(parent[x])
    return parent[x]

T = int(input())
for _ in range(T):
    parent = []
    n = int(input())
    for i in range(n):
        parent.append(i)
    k = int(input())
    for i in range(k):
        a, b = map(int, input().split())
        a = find(a)
        b = find(b)
        if a != b:
            if(a < b):
                parent[b] = a;
            else:
                parent[a] =b;

    m = int(input())
    print(f'Scenario {_+1}:', end='\n')
    for i in range(m):
        u, v = map(int, input().split())
        u = find(u)
        v = find(v)
        if u == v:
            print(1, end='\n')
        else:
            print(0, end='\n')

    print()