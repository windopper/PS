#include <bits/stdc++.h>

using namespace std;
long long tree[2000000];

void update(int s, int e, int i, int ui) {
    if(s > ui || e < ui) return;
    if(s == e) {
        tree[i] += 1;
        return;
    }
    int m = (s+e)/2;
    update(s, m, i*2, ui);
    update(m+1, e, i*2+1, ui);
    tree[i] = tree[i*2] + tree[i*2+1];
    return;
}

long long query(int s, int e, int i, int l, int r) {
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) return tree[i];
    int m = (s+e)/2;
    return query(s, m, i*2, l, r) + query(m+1, e, i*2+1, l, r);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; 
    cin >> N;
    vector<pair<int, int>> queries;
    for(int i=0; i<N; i++) {
        int t;
        cin >> t;
        queries.push_back({-t, N-i});
    }

    sort(queries.begin(), queries.end());

    long long ans = 0;
    vector<pair<int, long long>> result;
    for(pair<int, int> q : queries) {
        long long t = query(1, N, 1, q.second, 500000) + 1;
        result.push_back({-q.second, t});
        update(1, N, 1, q.second);
    }

    sort(result.begin(), result.end());
    for(int i=0; i<result.size(); i++) {
        cout << result[i].second << "\n";
    }
}