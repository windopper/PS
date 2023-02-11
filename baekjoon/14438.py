import sys, math
INF = math.inf
input = sys.stdin.readline
n = int(input())
arr = list(map(int, input().split()))
m = int(input())
tree = [INF] * (n*4)

def init(start, end, index):

    if start == end:
        tree[index] = arr[start-1]
        return tree[index]

    mid = (start+end) // 2
    l = init(start, mid, index*2)
    r = init(mid+1, end, index*2+1)
    tree[index] = min(l, r)
    return tree[index]

def query(start, end, index, left, right):
    if end < left or start > right:
        return INF
    if start >= left and end <= right:
        return tree[index]

    mid = (start+end) // 2
    l = query(start, mid, index*2, left, right)
    r = query(mid+1, end, index*2+1, left, right)
    return min(l, r)

def update(start, end, index, update_idx, update_data):
    if start > update_idx or end < update_idx:
        return

    if start == end:
        tree[index] = update_data
        arr[start-1] = update_data
        return

    mid = (start+end) // 2
    update(start, mid, index*2, update_idx, update_data)
    update(mid+1, end, index*2+1, update_idx, update_data)
    tree[index] = min(tree[index*2], tree[index*2+1])

init(1, n, 1)
for _ in range(m):
    a, b, c = map(int, input().split())
    if a == 1:
        # update
        update(1, n, 1, b, c)
    else:
        # query
        print(query(1, n, 1, b, c))