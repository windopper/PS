#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, M;
vector<pair<int, pair<int, int>>> q;
int parent[1001];
int ans = 0;

int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=1; i<N+1; i++) {
        parent[i] = i;
    }
    for(int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        q.push_back({c, {a, b}});
    }
    sort(q.begin(), q.end());

    for(int i=0; i<q.size(); i++) {
        int cost = q[i].first;
        int a = q[i].second.first;
        int b = q[i].second.second;
        a = find(a);
        b = find(b);
        if(a != b) {
            if ( a < b ) parent[b] = a;
            else parent[a] = b;
            ans += cost;
        }
    }
    cout << ans;
}