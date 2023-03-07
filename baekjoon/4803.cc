#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> graph;

bool dfs(vector<int>& visited, int x, int pre) {
    for (int i = 0; i < graph[x].size(); i++) {
        if (graph[x][i] == pre) continue;
        // 이전에 방문한건 그래프가 양방향이므로 무시하자
        if (visited[graph[x][i]]) return true;
        // 방문한거 또 방문하면 사이클이지
        visited[graph[x][i]] = 1;
        if (dfs(visited, graph[x][i], x)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c = 1;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;

        int treeCnt = 0;
        graph.assign(n + 1, vector<int>(0));
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        cout << "Case " << c++ << ": ";

        vector<int> visited(n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            if (visited[i]) continue;
            // 이미 방문한 그래프네
            visited[i] = 1;
            bool isCycle = dfs(visited, i, -1);
            if (!isCycle) ++treeCnt;
        }

        if (treeCnt == 1) {
            cout << "There is one tree.";
        } else if (treeCnt > 1) {
            cout << "A forest of " << treeCnt << " trees.";
        } else {
            cout << "No trees.";
        }
        cout << "\n";
    }
}