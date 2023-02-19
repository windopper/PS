#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<pair<int, pair<int, int>>> vec;
int parent[100001];
vector<int> costs;

int find(int i) {
    if(i == parent[i]) return i;
    return parent[i] = find(parent[i]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N+1; i++) parent[i] = i;
    for(int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vec.push_back({c, {a, b}});
    }
    sort(vec.begin(), vec.end());

    // 크루스칼
    for(int i=0; i<vec.size(); i++) {
        int cost = vec[i].first;
        int a = vec[i].second.first;
        int b = vec[i].second.second;
        a = find(a);
        b = find(b);
        if(a != b) {
            if (a < b) {
                parent[b] = a;
            }
            else {
                parent[a] = b;
            }
            costs.push_back(cost);
        }
    }
    int ans = 0;
    for(int i=0; i<costs.size()-1; i++) {
        ans += costs[i];
    }
    cout << ans;
}