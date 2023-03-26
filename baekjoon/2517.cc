#include <bits/stdc++.h>

using namespace std;
int N;
int arr[500001];
int tree[500001*4+4];

void update(int start, int end , int idx, int updateIdx) {
    if(start > updateIdx || end < updateIdx) return;
    if(start == end) {
        tree[idx] += 1;
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, idx*2, updateIdx);
    update(mid+1, end, idx*2, updateIdx);
    tree[idx] = tree[idx*2] = tree[idx*2+1];
}

int query(int start, int end, int idx, int left, int right) {
    if(start > right || end < left) return 0;
    if(start <= left && end >= right) return tree[idx];
    int mid = (start + end) / 2;
    return query(start, mid, idx*2, left, right) + query(mid+1, end, idx*2+1, left, right);
}

int find(int value, int index, int left, int right) {
    if(left == right) {
        return tree[index];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        update(1, N, 1, arr[i]);
    }
    for(int i=0; i<N; i++) {

    }
}