#include <bits/stdc++.h>

using namespace std;
int N, M;
int indegree[32001] = {0, };
map<int, vector<int>> graph;
priority_queue<int> pq;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        ++indegree[b];
        graph[a].push_back(b);
    }

    for(int i=1; i<N+1; i++) {
        if(indegree[i] == 0) {
            pq.push(-i);
        }
    }

    while(!pq.empty()) {
        int node = -pq.top();
        pq.pop();
        ans.push_back(node);
        for(int i=0; i<graph[node].size(); i++) {
            int nxt = graph[node][i];
            --indegree[nxt];
            if(indegree[nxt] == 0) {
                pq.push(-nxt);
            }
        }
    }

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
}