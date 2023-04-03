#include <bits/stdc++.h>

using namespace std;
vector<int> tree[400000];
int arr[100001];

void merge(vector<int>& cur, vector<int>& l, vector<int>& r) {
    for (int i = 0, j = 0, k = 0; i < cur.size(); i++) {
        if (r.size() == k || (j < l.size() && l[j] < r[k]))
            cur[i] = l[j++];
        else
            cur[i] = r[k++];
    }
}

int query(int s, int e, int i, int l, int r, int x) {
    if (e < l || s > r) return 0;
    vector<int>& cur = tree[i];
    if (s >= l && e <= r) {
        return upper_bound(cur.begin(), cur.end(), x) - cur.begin();
    }
    int m = (s + e) / 2;
    return query(s, m, i*2, l, r, x) + query(m+1, e, i*2+1, l, r, x);
}

void init(int s, int e, int i) {
    vector<int>& cur = tree[i];
    if (s == e) {
        cur.push_back(arr[s - 1]);
        return;
    }
    int m = (s + e) / 2;
    init(s, m, i * 2);
    init(m + 1, e, i * 2 + 1);
    vector<int>&l = tree[i * 2], &r = tree[i * 2 + 1];
    cur.resize(l.size() + r.size());
    merge(cur, l, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int maxElement = 0;
    int minElement = numeric_limits<int>::max();
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxElement = max(arr[i], maxElement);
        minElement = min(arr[i], minElement);
    }

    init(1, n, 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int s = minElement;
        int e = maxElement;
        int ans = 0;
        while(s<=e) {
            int m = (s+e)/2;
            int v = query(1, n, 1, a, b, m);
            // m이 정렬된 수열에 대하여 v번째 수일 때 c보다 작으면
            if(v < c) {
                s = m+1;
            }
            else if(v >= c) {
                ans = m;
                e = m-1;
            }
        } 
        cout << ans << "\n" ;
    }
}