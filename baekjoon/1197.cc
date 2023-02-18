#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
vector<pair<int, pair<int, int>>> graph;
int parent[10001];
int weight = 0;

int find(int x) {
    if ( parent[x] == x ) return x;
    return parent[x] = find(parent[x]);
}

void solve() {
    for(int i=0; i<E; i++) {
        int s = graph[i].second.second;
        int e = graph[i].second.first;
        int cost = graph[i].first;

        int a = find(s);
        int b = find(e);
        if(a == b) continue;

        // union
        if ( a < b ) parent[a] = b;
        else parent[b] = a;
        weight += cost;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> V >> E;
    for(int i=0; i<V+1; i++) {
        parent[i] = i;
    }
    for(int i=0; i<E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({c, {b, a}});
    }

    sort(graph.begin(), graph.end());

    solve();
    cout << weight;
}   