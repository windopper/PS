#include <bits/stdc++.h>

using namespace std;

vector<int> tree[400000];
int arr[100000];

void merge(vector<int>& cur, vector<int>& l, vector<int>& r) {
    int ptr = 0;
    for(int i=0, j=0, k=0; i<cur.size(); ++i) {
        if(k == r.size() || (j < l.size() && l[j] < r[k])) cur[i] = l[j++];
        else cur[i] = r[k++];
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
    if(e < l || s > r) return 0;
    if(s >= l && e <= r) {
        return tree[i].end() - upper_bound(tree[i].begin(), tree[i].end(), k);
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
    int L = 0;
    for(int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        L = query(1, N, 1, a^L, b^L, c^L);
        cout << L << "\n";
    }
}