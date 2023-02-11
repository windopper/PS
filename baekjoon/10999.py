import sys
input = sys.stdin.readline

def init(start, end, index):
    if start == end:
        tree[index] = arr[start-1]
        return tree[index]
    mid = (start + end) // 2
    tree[index] = init(start, mid, index*2) + init(mid+1, end, index*2+1)
    return tree[index]

def propagation(start, end, index):
    # 어떤 노드를 방문할 때마다 시행된다.
    if lazy[index] != 0:
        # lazy 값이 존재한다면 해당 노드의 합에 반영하고
        # 자식이 존재한다면 노드의 lazy에 넘긴다.
        tree[index] += (end-start+1) * lazy[index]
        # end-start+1는 구간의 각 수에 더해야 하는 값에 포함된 수의 개수만큼 곱해야 되므로
        # 계산한 값이다.
        if start != end:
            # 자식이 존재한다면 자식노드에 lazy를 추가한다.
            lazy[index*2] += lazy[index]
            lazy[index*2+1] += lazy[index]
        lazy[index] = 0

def update(start, end, index, left, right, update_data):
    propagation(start, end, index)
    if start > right or end < left:
        return

    if start >= left and end <= right:
        # 노드의 구간이 모두 포함되는 경우 더 이상 하위 노드까지
        # 내려갈 필요가 없으므로 현재 노드에서 갱신할 값만 바꾼 후
        # 나중에 계산할 노드 값은 lazy에 넣는다.
        # 이렇게 저장된 lazy는 어느 시점에서 어떤 구간의 값 갱신에서 propagation() 메서드를
        # 호출함으로써 계산될 수도 있다.
        tree[index] += (end-start+1) * update_data
        if start != end:
            # 해당 노드가 자식이 있는 경우 그 자식한테 lazy를 물려준다
            lazy[index*2] += update_data
            lazy[index*2+1] += update_data
        return

    # 여기부터 노드의 구간이 모두 포함되지 않는 경우이다.
    mid = (start + end) // 2
    update(start, mid, index*2, left, right, update_data)
    update(mid+1, end, index*2+1, left, right, update_data)
    tree[index] = tree[index*2] + tree[index*2+1]

def find(start, end, index, left, right):
    propagation(start, end, index)
    if start > right or end < left:
        return 0

    if left <= start and right >= end:
        return tree[index]

    mid = (start + end) // 2
    l = find(start, mid, index*2, left, right)
    r = find(mid+1, end, index*2+1, left, right)
    return l + r

n, m ,k = map(int, input().split())
arr = [int(input()) for _ in range(n)]
lazy = [0] * (n*4)
tree = [0] * (n*4)
init(1, n, 1)
for _ in range(m+k):
    i, *j = map(int, input().split())
    if i==1:
        b, c, d = j
        update(1, n, 1, b, c, d)
    else:
        b, c = j
        print(find(1, n, 1, b, c))