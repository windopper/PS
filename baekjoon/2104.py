import sys, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
INF = math.inf
n = int(input())
arr = list(map(int, input().split()))
tree = [0] * (n*4)

def init(start, end, index):
    if start == end:
        tree[index] = (start-1, arr[start-1])
        return tree[index]

    mid = (start+end) // 2
    l1, l2 = init(start, mid, index*2)
    r1, r2 = init(mid+1, end, index*2+1)
    small_index = l1 if arr[l1] < arr[r1] else r1
    sub_sum = l2 + r2
    tree[index] = (small_index, sub_sum)
    return tree[index]

def query(start, end, index, left, right):
    if end < left or start > right:
        return -1
    if start >= left and end <= right:
        return tree[index]

    mid = (start+end) // 2
    l = query(start, mid, index*2, left, right)
    r = query(mid+1, end, index*2+1, left, right)
    if l == -1:
        return r
    elif r == -1:
        return l
    else:
        return (l[0] if arr[l[0]] < arr[r[0]] else r[0], l[1] + r[1])

def divide_and_conquer(start, end):

    min_index, score = query(1, n, 1, start, end)
    score = score * arr[min_index]
    min_index += 1
    if start <= min_index - 1:
        tmp_score = divide_and_conquer(start, min_index-1)
        score = max(score, tmp_score)
   
    if end >= min_index + 1:
        tmp_score = divide_and_conquer(min_index+1, end)
        score = max(score, tmp_score)
    
    return score

init(1, n, 1)
print(divide_and_conquer(1, n))

