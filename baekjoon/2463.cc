#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1e9;
int parent[100001];
int level[100001] = {0, };
int groupCnt[100001] = {0, };
long long sum = 0;

int find(int cur) {
    if (cur == parent[cur]) return cur;
    return parent[cur] = find(parent[cur]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        groupCnt[i] = 1;
    }
    
    vector<vector<int>> edges;
    for (int i = 0; i < M; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        sum += w;
        edges.push_back({-w, x, y});
    }

    sort(edges.begin(), edges.end());
    long long ans = 0;
    long long temp = 0;
    for (vector<int> edge : edges) {
        int w = -edge[0];
        int u = edge[1];
        int v = edge[2];
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            ans += ((((long long)groupCnt[pu] * groupCnt[pv]) % MOD) * sum) % MOD;
            ans %= MOD;
            if (level[pu] > level[pv]) swap(pu, pv);
            if(level[pu] == level[pv]) level[pv]++;
            parent[pv] = pu;
            groupCnt[pu] += groupCnt[pv];
            groupCnt[pv] = groupCnt[pu];
        }
        sum -= w;
    }

    cout << ans;
}