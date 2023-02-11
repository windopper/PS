import sys, math
input = sys.stdin.readline
n, m = map(int, input().split())
arr = [int(input()) for _ in range(n)]
query = [tuple(map(int, input().split())) for _ in range(m)]
tree = [math.inf] * (n*4)
def init(start, end, index):
    if start == end:
        tree[index] = arr[start-1]
        return tree[index]

    mid = (start + end) // 2
    l = init(start, mid, index*2)
    r = init(mid+1, end, index*2+1)
    tree[index] = l if l < r else r
    return tree[index]

def find(start, end, index, left, right):
    if start > right or end < left:
        return math.inf
    if start >= left and end <= right:
        return tree[index]
    
    mid = (start + end) // 2
    l = find(start, mid, index*2, left, right)
    r = find(mid+1, end, index*2+1, left, right)
    return l if l < r else r

init(1, n, 1)
for a, b in query:
    print(find(1, n, 1, a, b))
