#include <algorithm>
#include <iostream>

using namespace std;
int N, M;

int tree[4000004] = {0, };

void update(int start, int end, int index, int updateIdx, int updateData) {
    if(start > updateIdx || end < updateIdx) return;
    if(start == end) {
        tree[index] = updateData;
        return;
    }
    int mid = (start+end) / 2;
    update(start, mid, index*2, updateIdx, updateData);
    update(mid+1, end, index*2+1, updateIdx, updateData);
    tree[index] = max(tree[index*2], tree[index*2+1]);
}

int query(int start, int end, int index, int left, int right) {
    if(start > right || end < left) return 0;
    if(start >= left && end <= right) return tree[index];
    int mid = (start + end) / 2;
    int l = query(start, mid, index*2, left, right);
    int r = query(mid+1, end, index*2+1, left, right);
    return max(l, r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        update(1, N, 1, i+1, temp);
    };

    for(int i=M; i<=N-M+1; i++) {
        cout << query(1, N, 1, i-(M-1), i+(M-1)) << " ";
    }
}