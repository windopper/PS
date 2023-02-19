#include <iostream>

using namespace std;
int N, M;
int tree[400004] = {0, };
int lazy[400004] = {0, };

void propagation(int s, int e, int idx) {
    if (lazy[idx] != 0) {
        // 갱신이 필요하다면
        tree[idx] = e - s + 1 - tree[idx];
        // 개수 반전
        if (s != e) {
            // 하위 노드가 있다면
            lazy[idx*2] = !lazy[idx*2];
            lazy[idx*2+1] = !lazy[idx*2+1];
            // 다음 갱신 때 개수 반전이 필요하겠지? 라고 알려줌
        }
        lazy[idx] = 0;
    }
}

void update(int s, int e, int idx, int l , int r) {
    propagation(s, e, idx);
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        // 트리 범위 안에 있다면
        tree[idx] = (e-s+1) - tree[idx];
        // 개수 반전
        if(s != e) {
            // 하위 노드가 있다면
            lazy[idx*2] = !lazy[idx*2];
            lazy[idx*2+1] = !lazy[idx*2+1];
        }
        return;
    }
    int mid = (s + e) / 2;
    update(s, mid, idx*2, l, r);
    update(mid+1, e, idx*2+1, l, r);
    tree[idx] = tree[idx*2] + tree[idx*2+1];
}

int find(int s, int e, int idx, int l, int r) {
    propagation(s, e, idx);
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) return tree[idx];
    int mid = (s + e) / 2;
    return find(s, mid, idx*2, l, r) + find(mid+1, e, idx*2+1, l, r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(; M>0; M--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0) {
            update(1, N, 1, b, c);
        }
        else {
            cout << find(1, N, 1, b, c) << "\n";
        }
    }
}