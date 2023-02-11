import sys, math
INF = math.inf
input = sys.stdin.readline

def init(start, end, index):
    if start == end:
        tree[index] = (arr[start-1], start)
        return
    mid = (start+end) // 2
    init(start, mid, index*2)
    init(mid+1, end, index*2+1)
    l = tree[index*2]
    r = tree[index*2+1]
    if l[0] < r[0]:
        tree[index] = (l[0], l[1])
    elif l[0] > r[0]:
        tree[index] = (r[0], r[1])
    else:
        if l[1] < r[1]:
            tree[index] = (l[0], l[1])
        else:
            tree[index] = (r[0], r[1])

def update(start, end, index, update_idx, update_data):
    if start > update_idx or end < update_idx:
        return
    if start == end:
        arr[start-1] = update_data
        tree[index] = (update_data, start)
        return

    mid = (start+end) // 2
    update(start, mid, index*2, update_idx, update_data)
    update(mid+1, end, index*2+1, update_idx, update_data)
    l = tree[index*2]
    r = tree[index*2+1]
    if l[0] < r[0]:
        tree[index] = (l[0], l[1])
    elif l[0] > r[0]:
        tree[index] = (r[0], r[1])
    else:
        if l[1] < r[1]:
            tree[index] = (l[0], l[1])
        else:
            tree[index] = (r[0], r[1])

def query(start, end, index, left, right):
    if end < left or start > right:
        return (INF, -1)
    if start >= left and end <= right:
        return tree[index]

    mid = (start + end) // 2
    l = query(start, mid, index*2, left, right)
    r = query(mid+1, end, index*2+1, left, right)
    if l[0] < r[0]:
        return (l[0], l[1])
    elif l[0] > r[0]:
        return (r[0], r[1])
    else:
        if l[1] < r[1]:
            return (l[0], l[1])
        else:
            return (r[0], r[1])

n = int(input())
arr = list(map(int, input().split()))
tree = [0] * (n*4)
m = int(input())

init(1, n, 1)
for _ in range(m):
    a, b, c = map(int, input().split())
    if a == 1:
        # update
        update(1, n, 1, b, c)
    else:
        # query
        print(query(1, n, 1, b, c)[1])