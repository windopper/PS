#include <bits/stdc++.h>

using namespace std;
int N;
int arr[100001];
int tree[400004];

void update(int s, int e, int i, int ui, int diff) {
    if(ui < s || e < ui) return;
    if(s == e) {
        tree[i] = diff;
        return;
    }
    int m = (s+e)/ 2;
    update(s, m, i*2, ui, diff);
    update(m+1, e, i*2+1, ui, diff);
    tree[i] = tree[i*2] + tree[i*2+1];
}

int query(int s, int e, int i, int l, int r) {
    if(r < s || l > e) return 0;
    if(l <= s && r >= e) return tree[i];
    int m = (s+e)/2;
    return query(s, m, i*2, l, r) + query(m+1, e, i*2+1, l, r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1; i<N+1; i++) {
        int tmp;
        cin >> tmp;
        if(tmp % 2 == 0) {
            update(1, N, 1, i, 1);
        }
    }
    int M;
    cin >> M;
    for(int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            if(c % 2 == 1) {
                update(1, N, 1, b, 0);
            }
            else {
                update(1, N, 1, b, 1);
            }
        }
        else if(a == 2) {
            cout << query(1, N, 1, b, c);
            cout << "\n";
        }
        else {
            cout << c - b + 1 - query(1, N, 1, b, c);
            cout << "\n";
        }

    }
}