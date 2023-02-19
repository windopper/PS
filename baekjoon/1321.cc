#include <iostream>

using namespace std;
int N, M;
int unit[500001];
int tree[500001*4];

int init(int start, int end, int index) {
    if(start == end) {
        return tree[index] = unit[start-1];
    }
    int mid = (start + end) / 2;
    return tree[index] = init(start, mid, index*2) + init(mid+1, end, index*2+1);
}

int update(int start, int end, int index, int updateIdx, int updateData) {
    if(start > updateIdx || end < updateIdx) return tree[index];
    if(start == end) {
        tree[index] += updateData;
        return tree[index];
    }
    int mid = (start + end) / 2;
    int l = update(start, mid, index*2, updateIdx, updateData);
    int r = update(mid+1, end, index*2+1, updateIdx, updateData);
    return tree[index] = l + r;
}

int find(int left, int right, int index, int target) {
    if(left == right) {
        return left;
    }
    int mid = (left + right) / 2;
    if(target <= tree[index*2]) {
        // 트리의 왼쪽으로 가야될 때
        return find(left, mid, index*2, target);
    }
    else {
        return find(mid+1, right, index*2+1, target - tree[index*2]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) cin >> unit[i];
    init(1, N, 1);
    cin >> M;
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        if(a == 1) {
            int c;
            cin >> c;
            update(1, N, 1, b, c);
        }
        else {
            cout << find(1, N, 1, b) << "\n";
        }
    }
}

