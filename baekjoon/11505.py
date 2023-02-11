import sys
input = sys.stdin.readline
DIV = 1000000007
def init(s, e, i):
    if s == e:
        tree[i] = arr[s-1]
        return tree[i]

    m = (s+e) // 2
    l = init(s, m, i*2)
    r = init(m+1, e, i*2+1)
    tree[i] = l * r % DIV
    return tree[i]

def find(s, e, i, left, right):
    if s > right or e < left:
        return 1
    if s >= left and e <= right:
        return tree[i]

    m = (s+e) // 2
    l = find(s, m, i*2, left, right)
    r = find(m+1, e, i*2+1, left, right)
    return l*r % DIV

def update(s, e, i, update_idx, update_data):
    if s > update_idx or e < update_idx:
        return

    if s == e:
        tree[i] = update_data   
        return 

    m = (s+e) // 2
    update(s, m, i*2, update_idx, update_data)
    update(m+1, e, i*2+1, update_idx, update_data)
    tree[i] = tree[i*2] * tree[i*2+1] % DIV

n, m, k = map(int, input().split())
arr = [int(input()) for _ in range(n)]
tree = [0] * (n*4)
query = []

init(1, n, 1)

for _ in range(m+k):
    a, b, c = map(int, input().split())
    if a == 1:
        update(1, n, 1, b, c)
        arr[b-1] = c
    else:
        print(int(find(1, n, 1, b, c)))
