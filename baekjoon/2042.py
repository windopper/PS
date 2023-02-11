import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())
segment_tree = [0] * (n*4)
arr = []

"""
트리 초기화 함수
start, end는 트리의 범위로 같다면 리프노드를 의미한다.
"""
def init(start, end, index):
		# 같다면 리프노드이다. 리프노드에는 우리가 배열에 저장했던 수를 놓는다
    if start == end:
        segment_tree[index] = arr[start-1]
        return segment_tree[index]
		
		# 아직 리프노드에 도달하지 않았다면 범위를 쪼개 리프노드에 도달할 때 까지 진행한다.
		# 왼쪽 아래 노드는 현재 인덱스에서 2를 곱한 것이고
		# 오른쪽 아래 노드는 현재 인덱스에서 2를 곱하고 1을 더한 것이다.
    mid = (start + end) // 2
    segment_tree[index] = init(start, mid, index*2) + init(mid+1, end, index*2+1)
    return segment_tree[index]

"""
트리에서 값 찾기
start, end는 트리의 범위, index는 노드 고유번호, left, right는 탐색 범위이다.
"""
def find(start, end, index, left, right):
		# 트리의 범위에 속하지 않는 다면 0을 반환
    if start > right or end < left:
        return 0
		# 트리의 범위에 속한다면 이는 트리의 노드에 저장된 구간합이 있다는 뜻으로
		# 이를 반환한다. 
    if start >= left and end <= right:
        return segment_tree[index]
    
		# 트리의 범위에 부분적으로 속한다면 범위를 쪼개 완전히 속하는 노드를 찾는다.
    mid = (start + end) // 2
    sub_sum = find(start, mid, index*2, left, right) + find(mid+1, end, index*2+1, left, right)
    return sub_sum

def update(start, end, index, update_idx, update_data):
    if start > update_idx or end < update_idx:
        return
    
    segment_tree[index] += update_data

    if start == end:
        return

    mid = (start + end) // 2
    update(start, mid, index*2, update_idx, update_data)
    update(mid+1, end, index*2+1, update_idx, update_data)

for _ in range(n):
    arr.append(int(input()))

init(1, n, 1)

for _ in range(m+k):
    a, b, c = map(int, input().split())
    if a == 1:
        temp = c - arr[b-1]
        arr[b-1] = c
        update(1, n, 1, b, temp)
    else:
        print(find(1, n, 1, b, c))