#include <bits/stdc++.h>

using namespace std;
long long N, K, Q;
int cnt = 1;
vector<int> parent;
vector<int> level;

void createTree() {
    queue<int> q;
    q.push(cnt++);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < K; i++) {
            if (cnt > N) return;
            q.push(cnt);
            parent[cnt] = cur;
            level[cnt] = level[cur] + 1;
            ++cnt;
        }
    }
}

int lca(int a, int b) {
    int originalA = a, originalB = b;
    if (level[a] < level[b]) swap(a, b);
    int diff = level[a] - level[b];
    for (; diff > 0; --diff) {
        a = parent[a];
    }

    int ret = a;
    if (a != b) {
        while (parent[a] != 0 && parent[a] != parent[b]) {
            a = parent[a];
            b = parent[b];
        }
        ret = parent[a];
    }
    return level[originalA] + level[originalB] - 2 * level[ret];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K >> Q;
    parent.resize(N + 1);
    level.resize(N + 1);
    createTree();

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}