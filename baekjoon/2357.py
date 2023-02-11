import sys, math
MAX = math.inf
MIN = -math.inf
input = sys.stdin.readline
n, m = map(int, input().split())
arr = [int(input()) for _ in range(n)]
query = []
tree = [0] * (n*4)
for _ in range(m):
    a, b = map(int, input().split())
    query.append((a, b))

def init(start, end, index):
    if start == end:
        tree[index] = [arr[start-1], arr[start-1]]
        
        return tree[index]
    
    mid = (start + end) // 2
    l = init(start, mid, index*2)
    r = init(mid+1, end, index*2 + 1)
    temp = [MAX, MIN] # min, max
    if l[0] < r[0]:
        temp[0] = l[0]
    else:
        temp[0] = r[0]

    if l[1] < r[1]:
        temp[1] = r[1]
    else:
        temp[1] = l[1]

    tree[index] = temp
    return temp

def find(start, end, index, left, right):
    if end < left or start > right:
        return (MAX, MIN)
    if start >= left and end <= right:
        return tree[index]

    mid = (start + end) // 2
    l = find(start, mid, index*2, left, right)
    r = find(mid+1, end, index*2+1, left, right)
    temp = [MAX, MIN]
    if l[0] < r[0]:
        temp[0] = l[0]
    else:
        temp[0] = r[0]

    if l[1] < r[1]:
        temp[1] = r[1]
    else:
        temp[1] = l[1]

    return temp


init(1, n, 1)
for a, b in query:
    print(*find(1, n, 1, a, b), sep=' ')


