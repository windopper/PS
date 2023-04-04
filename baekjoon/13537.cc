#include <bits/stdc++.h>

using namespace std;
int arr[100001];
vector<int> tree[400004];

void merge(vector<int>& cur, vector<int>& l, vector<int>& r) {
    for(int i=0, j=0, k=0; i<cur.size(); i++) {
        if(k == r.size() || (j < l.size() && l[j] < r[k])) {
            cur[i] = l[j++];
        }
        else {
            cur[i] = r[k++];
        }
    }
}

void init(int s, int e, int i) {
    vector<int>& cur = tree[i];
    if(s == e) {
        cur.push_back(arr[s-1]);
        return;
    }
    int m = (s+e)/2;
    init(s, m, i*2);
    init(m+1, e, i*2+1);
    vector<int>& l = tree[i*2], &r = tree[i*2+1];
    cur.resize(l.size() + r.size());
    merge(cur, l, r);
}

int query(int s, int e, int i, int l, int r, int k) {
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) {
        vector<int>& cur = tree[i];
        return cur.end() - upper_bound(cur.begin(), cur.end(), k);
    }
    int m = (s+e)/2;
    return query(s, m, i*2, l, r, k) + query(m+1, e, i*2+1, l, r, k);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }   
    init(1, N, 1);
    int M;
    cin >> M;
    for(int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << query(1, N, 1, a, b, c) << "\n";
    }
}