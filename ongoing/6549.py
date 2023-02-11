import sys, math
input = sys.stdin.readline

while True:
    arr = [*list(map(int, input().split()))]
    if arr[0] == 0:
        break
    tree = [0] * (arr[0] * 4)

    ans = -math.inf

    def init(start, end, index):
        """
        각 노드는 최소 높이의 인덱스를 저장한다.
        이는 후에 구간별 넓이를 계산할 때 최소 높이가 저장된 인덱스를 활용한다.
        """
        if start == end:
            tree[index] = start
            return tree[index]

        mid = (start + end) // 2
        l_min_idx = init(start, mid, index*2)
        r_min_idx = init(mid+1, end, index*2+1)
        tree[index] = arr[l_min_idx] if arr[l_min_idx] < arr[r_min_idx] else arr[r_min_idx]
        return tree[index]

    def query(start, end, index, left, right):
        if end < left or start > right:
            return -1
        if start >= left and end <= right:
            return tree[index]
        mid = (start + end) // 2
        l_min_idx = query(start, mid, index, left, right)
        r_min_idx = query(mid+1, end, index, left, right)
        if l_min_idx == -1:
            return r_min_idx
        elif r_min_idx == -1:
            return l_min_idx
        else:
            temp = arr[l_min_idx] if arr[l_min_idx] < arr[r_min_idx] else arr[r_min_idx]
            return temp

    def max_area(start, end):
        n = arr[0]
        m = query(start, end, 1, 1, n)

        area = (end-start+1)*arr[m]

        if start <= m-1:
            temp = max_area(start, m-1)
            if area < temp:
                area = temp
        
        if m+1 <= end:
            temp = max_area(m+1, end)
            if area < temp:
                area = temp

        return area

    init(1, arr[0], 1)
    print(max_area(1, arr[0]))
    


