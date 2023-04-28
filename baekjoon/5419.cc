#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int T;

long long tree[1<<18];
long long base = 1<<17;

void update(int x, int v) {
    x |= base;
    tree[x] += v;
    while(x >>= 1) {
        tree[x] = tree[x << 1] + tree[x << 1 | 1];
    }
}

long long query(int l, int r) {
    l |= base;
    r |= base;
    long long ret = 0;
    while(l <= r) {
        if(l & 1) ret += tree[l++];
        if(~r & 1) ret += tree[r--];
        l >>= 1, r >>= 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        memset(tree, 0, sizeof(tree));
        int n;
        cin >> n;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr.begin(), arr.end(), [](pii& a, pii& b) {
            return a.second < b.second;
        });

        vector<int> newY(n);

        int idx = 0;
        for(int i=0; i<arr.size(); i++) {
            if(i > 0 && arr[i].second != arr[i-1].second) ++idx;
            newY[i] = idx;
        }

        for(int i=0; i<arr.size(); i++) {
            arr[i].second = newY[i];
        }

        sort(arr.begin(), arr.end(), [](pii& a, pii& b) {
            return a.first != b.first ? a.first < b.first : a.second > b.second;
        });

        long long res = 0;
        for(int i=0; i<n; i++) {
            res += query(arr[i].second, n);
            update(arr[i].second, 1);
        }
        cout << res << "\n";
    }
}