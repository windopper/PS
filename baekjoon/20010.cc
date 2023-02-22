#include <bits/stdc++.h>

using namespace std;
int N, K;
vector<pair<int, pair<int, int>>> arr;
vector<int> parents;
vector<vector<pair<int, int>>> graph;

int find(int x) {
    if(x == parents[x]) return x;
    return parents[x] = find(parents[x]);
}

int dfs(vector<int>& visited, int s, int value) {
    for(int i=0; i<graph[s].size(); i++) {
        int cost = graph[s][i].first;
        int next = graph[s][i].second;
        value += cost;
        return dfs(visited, next, value);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    int minCost = 0;
    parents.resize(N+1);
    for(int i=0; i<N; i++) {
        vector<pair<int, int>> vec;
        parents[i] = i;
        graph.push_back(vec);
    }
    for(int i=0; i<K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back({c, {a, b}});
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<arr.size(); i++) {
        int cost = arr[i].first;
        int a = arr[i].second.first;
        int b = arr[i].second.second;
        a = find(a);
        b = find(b);
        if (a != b) {
            if (a < b) {
                parents[b] = a;
            }
            else parents[a] = b;

            minCost += cost;
            graph[a].push_back({cost, a});
            graph[b].push_back({cost, b});
        }   
    }
    for(int i=0; i<graph.size(); i++) {
        sort(graph[i].begin(), graph[i].end());
    }

}