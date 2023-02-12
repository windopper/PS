import sys
import heapq
input = sys.stdin.readline

def init(start, end, index):
    if start == end:
        tree[index] = start-1
        return tree[index]
    
    mid = (start+end)//2
    l = init(start, mid, index*2)
    r = init(mid+1, end, index*2+1)
    tmp = -1
    if arr[l] < arr[r]:
        tmp = l
    elif arr[r] < arr[l]:
        tmp = r
    else:
        if l < r:
            tmp = l
        else:
            tmp = r
    tree[index] = tmp
    return tmp

def update(start, end, index, update_idx, update_data):
    if start > update_idx or end < update_idx:
        return
    if start == end:
        # arr[start-1] = update_data
        tree[index] = start-1
        return

    mid = (start+end)//2
    l = init(start, mid, index*2)
    r = init(mid+1, end, index*2+1)
    tmp = -1
    if arr[l] < arr[r]:
        tmp = l
    elif arr[r] < arr[l]:
        tmp = r
    else:
        if l < r:
            tmp = l
        else:
            tmp = r
    tree[index] = tmp

def query(start, end, index, target):
    if start > target or end < target:
        return -1
    if start <= target <= end:
        return tree[index]
    mid = (start+end) // 2
    l = query(start, mid, index*2, target)
    r = query(mid+1, end, index*2+1, target)
    if l == -1:
        return r
    elif r == -1:
        return l
    else:
        if arr[l] < arr[r]:
            return l
        elif arr[r] < arr[l]:
            return r
        else:
            if l < r:
                return l
            else:
                return r

n = int(input())
arr = list(map(int, input().split()))
tree = [0] * (n*4)
m = int(input())
init(1, n, 1)
for _ in range(m):
    q, *a = map(int, input().split())
    if q == 1:
        arr[a[0]-1] = a[1]
        update(1, n, 1, a[0], a[1])
    else:
        print(tree[1] + 1)