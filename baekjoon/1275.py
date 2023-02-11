import sys
input = sys.stdin.readline

def init(start, end, index):
    if start == end:
        tree[index] = arr[start-1]
        return tree[index]

    mid = (start+end) // 2
    tree[index] = init(start, mid, index*2) + init(mid+1, end, index*2+1)
    return tree[index]

def find(start, end, index, left, right):
    if end < left or start > right:
        return 0
    if start >= left and end <= right:
        return tree[index]

    mid = (start + end) // 2
    sub_sum = find(start, mid, index*2, left, right) +\
        find(mid+1, end, index*2+1, left, right)
    return sub_sum

def update(start, end, index, update_idx, update_data):
    if end < update_idx or start > update_idx:
        return
    
    if start == end:
        tree[index] = update_data
        return

    mid = (start + end) // 2
    update(start, mid, index*2, update_idx, update_data)
    update(mid+1, end, index*2+1, update_idx, update_data)

    tree[index] = tree[index*2] + tree[index*2+1]

n, q = map(int, input().split())
arr = list(map(int, input().split()))
tree = [0] * (n*4)
turn = []

init(1, n, 1)
for _ in range(q):
    x, y, a, b = map(int, input().split())
    if x > y:
        temp = y
        y = x
        x = temp
    sub_sum = find(1, n, 1, x, y)
    update(1, n, 1, a, b)
    print(sub_sum)

    