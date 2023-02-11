import sys
input = sys.stdin.readline
n = int(input())
tree = [0] * (1000001 * 4)

"""
해당 트리에서 노드들은 사탕의 개수를 의미하고 사탕 배열의 인덱스는 사탕의 맛이다.
구간 합들은 하위 노드들의 사탕의 개수를 설정하여 사탕의 등수를 통해 어떤 사탕의
맛을 사용해야하는지 판별하는데 쓰인다.
"""

def update(start, end, index, update_idx, update_data):
    if start > update_idx or end < update_idx:
        return tree[index]
    if start == end:
        tree[index] += update_data
        return tree[index]
    mid = (start + end) // 2
    l = update(start, mid, index*2, update_idx, update_data)
    r = update(mid+1, end, index*2+1, update_idx, update_data)
    tree[index] = l + r
    return tree[index]

def get(start, end, index, target):
    if start == end:
        return start
    
    mid = (start + end) // 2
    # 사탕의 등수가 왼트리의 총 사탕의 개수보다 작으면
    # 왼트리에서 사탕의 등수 판별을 하기 위해 이동한다.
    if target <= tree[index*2]:
        return get(start, mid, index*2, target)
    else:
        return get(mid+1, end, index*2+1, target-tree[index*2])
ans = []
for _ in range(n):
    v = list(map(int, input().split()))
    if v[0] == 1:
        b = v[1]
        # b는 제거할 사탕의 등수이다.
        candy = get(1, 1000001, 1, b)
        # candy는 사탕의 맛
        ans.append(candy)
        update(1, 1000001, 1, candy, -1)
        # 해당 사탕의 맛이 있는 사탕 개수에서 -1을 한다.
    elif v[0] == 2:
        b, c = v[1], v[2]
        # b -> 사탕의 맛 c -> 사탕의 개수
        update(1, 1000001, 1, b, c)
print(*ans, sep='\n')