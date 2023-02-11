import sys, math
sys.setrecursionlimit(10**6)
input = sys.stdin.readline
INF = math.inf
n = int(input())
arr = list(map(int, input().split()))
tree_sum = [0] * (n*4)
tree_min_index = [0] * (n*4)

def init_min_index(start, end, index):
    if start == end:
        tree_min_index[index] = start-1
        return tree_min_index[index]

    mid = (start+end) // 2
    l = init_min_index(start, mid, index*2)
    r = init_min_index(mid+1, end, index*2+1)
    tree_min_index[index] = l if arr[l] < arr[r] else r
    return tree_min_index[index]

def query_min_index(start, end, index, left, right):
    if end < left or start > right:
        return None
    if start >= left and end <= right:
        return tree_min_index[index]

    mid = (start+end) // 2
    l = query_min_index(start, mid, index*2, left, right)
    r = query_min_index(mid+1, end, index*2+1, left, right)
    if l == None:
        return r
    elif r == None:
        return l
    else:
        return l if arr[l] < arr[r] else r

def init_sum(start, end, index):
    if start == end:
        tree_sum[index] = arr[start-1]
        return tree_sum[index]

    mid = (start+end)//2
    l = init_sum(start, mid, index*2)
    r = init_sum(mid+1, end, index*2+1)
    tree_sum[index] = l + r
    return tree_sum[index]

def query_sum(start, end, index, left, right):
    if end < left or start > right:
        return 0
    if start >= left and end <= right:
        return tree_sum[index]

    mid = (start+end)//2
    l = query_sum(start, mid, index*2, left, right)
    r = query_sum(mid+1, end, index*2+1, left, right)
    return l + r

def divide_and_conquer(start, end):

    min_index = query_min_index(1, n, 1, start, end)
    score = query_sum(1, n, 1, start, end) * arr[min_index]

    min_index += 1
    if start <= min_index - 1:
        tmp_score = divide_and_conquer(start, min_index-1)
        if score < tmp_score:
            score = tmp_score
   
    if end >= min_index + 1:
        tmp_score = divide_and_conquer(min_index+1, end)
        if score < tmp_score:
            score = tmp_score
    
    return score

init_min_index(1, n, 1)
init_sum(1, n, 1)
print(divide_and_conquer(1, n))

