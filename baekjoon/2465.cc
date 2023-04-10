#include <bits/stdc++.h>

using namespace std;
int tree[400001];
int arr[100001];
int S[100001];
int ans[100001];

void init(int s, int e, int i) {
    if (s == e) {
        tree[i] = 1;
        return;
    }
    int m = (s + e) / 2;
    init(s, m, i * 2);
    init(m + 1, e, i * 2 + 1);
    tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

void update(int s, int e, int i, int target, int count) {
    --tree[i];
    if (s == e) {
        ans[target] = arr[s];
        return;
    }
    int m = (s + e) / 2;
    if (count < tree[i * 2]) {
        update(s, m, i * 2, target, count);
    } else {
        update(m + 1, e, i * 2 + 1, target, count - tree[i * 2]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for (int i = 1; i < N+1; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < N+1; i++) {
        cin >> S[i];
    }
    sort(arr+1, arr+N+1);
    init(1, N, 1);
    for(int i=N; i>=1; --i) {
        update(1, N, 1, i, S[i]);
    }
    for(int i=1; i<N+1; i++) {
        cout << ans[i] << "\n";
    }
}