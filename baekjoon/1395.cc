#include <iostream>

using namespace std;
int N, M;
int arr[100001] = {0, };
int tree[400004] = {0, };
int lazy[400004] = {0, };

int sum(int i) {
    int ans = 0;
    while( i > 0 ) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

int sum(int i, int j) {
    return sum(j) - sum(i-1);
}

void update(int i) {
    int status = sum(i, i);
    while(i < 400004) {
        if(status == 1) {
            tree[i] -= 1;
        }
        else {
            tree[i] += 1;
        }
        i += (i & -i);
    }
}

void update(int i, int j) {
    for(; i<=j; i++) {
        update(i);
    }
}

void propagation(int s, int e, int idx) {
    if (lazy[idx] != 0) {
        tree[idx] = (e-s+1) - tree[idx];
        if (s != e) {
            lazy[idx*2] = !lazy[idx];
            lazy[idx*2+1] = !lazy[idx];
        }
        lazy[idx] = 0;
    }
}

int update(int s, int e, int idx, int l , int r) {
    propagation(s, e, idx);
    if(s > r || e < l) return;
    if(s >= l && e <= r) return tree[idx];
    int mid = (s + e) / 2;
    return update(s, mid, idx*2, l, r) + update(mid+1, e, idx*2+1, l, r);
}

int find(int s, int e, int idx, int l, int r) {
    if(s > r || e < l) return;
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
            update(b, c);
        }
        else {
            cout << sum(b, c) << "\n";
        }
    }
}