import sys
input = sys.stdin.readline

def init(start, end, index):
    
    if start == end:
        tree[index] = arr[start-1]
        return

    mid = (start+end) // 2
    init(start, mid, index*2)
    init(mid+1, end, index*2+1)
    tree[index] = tree[index*2] + tree[index*2+1]

def update(start, end, index, left, right, diff):
    propagation(start, end, index)
    if end < left or start > right:
        return
    if start >= left and end <= right:
        tree[index] += (end-start+1) * diff
        if start != end:
            lazy[index*2] += diff
            lazy[index*2+1] += diff
        return tree[index]

    mid = (start+end) // 2
    update(start, mid, index*2, left, right, diff)
    update(mid+1, end, index*2+1, left, right, diff)
    tree[index] = tree[index*2] + tree[index+1]

def find(start, end, index, target):
    propagation(start, end, index)
    if target < start or end < target:
        return None
    if start == end:
        return tree[index]

    mid = (start+end) // 2
    l = find(start, mid, index*2, target)
    r = find(mid+1, end, index*2+1, target)
    if l is None:
        return r
    else:
        return l
    return None


def propagation(start, end, index):
    tree[index] += (end-start+1) * lazy[index]
    if end != start:
        lazy[index*2] += lazy[index]
        lazy[index*2+1] += lazy[index]
    lazy[index] = 0

n = int(input())
arr = list(map(int, input().split()))
tree = [0] * (n*4)
lazy = [0] * (n*4)
m = int(input())

init(1, n, 1)
for _ in range(m):
    a, *q = map(int, input().split())
    if a == 1:
        b, c, d = q
        update(1, n, 1, b, c, d)
    else:
        print(find(1, n, 1, q[0]))
        pass