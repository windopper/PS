import sys
input = sys.stdin.readline
n, m = map(int, input().split())
arr = [0]*(n*4)
tree = [0]*(n*4)

def modify(start, end, index, update_idx, update_data):
    if end < update_idx or start > update_idx:
        return
    if start == end:
        tree[index] = update_data
        return

    mid = (start + end) // 2
    modify(start, mid, index*2, update_idx, update_data)
    modify(mid+1, end, index*2+1, update_idx, update_data)
    tree[index] = tree[index*2] + tree[index*2+1]

def sum(start, end, index, left, right):

    if end < left or start > right:
        return 0

    if start >= left and end <= right:
        return tree[index]
    
    mid = (start + end) // 2
    l = sum(start, mid, index*2, left, right)
    r = sum(mid+1, end, index*2+1, left, right)
    return l + r

for _ in range(m):
    a, b, c = map(int, input().split())
    if a == 0:
        # sum
        if b < c:
            print(sum(1, n, 1, b, c))
        else:
            print(sum(1, n, 1, c, b))
    else:
        # modify
        modify(1, n, 1, b, c)
        pass