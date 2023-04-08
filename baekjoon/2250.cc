#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> level(10001, {numeric_limits<int>::max(), 0});
int loc[10001];
int l = 1;
int maxLevel = 0;

vector<pair<int, int>> arr(10001);

void dfs(int cur, int depth) {
    if(cur == -1) return;
    if(arr[cur].first == -1 && arr[cur].second == -1) {
        level[depth].first = min(level[depth].first, l);
        level[depth].second = max(level[depth].second, l);
        maxLevel = max(maxLevel, depth);
        ++l;
        return;
    }

    dfs(arr[cur].first, depth+1);
    level[depth].first = min(level[depth].first, l);
    level[depth].second = max(level[depth].second, l);
    maxLevel = max(maxLevel, depth);
    ++l;
    dfs(arr[cur].second, depth+1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<int> indegree(N+1, 0);
    for(int i=0; i<N; i++) {
        int n, l, r;
        cin >> n >> l >> r;
        if(l!=-1) ++indegree[l];
        if(r!=-1) ++indegree[r];
        arr[n].first = l;
        arr[n].second = r;
    }

    int parent = -1;
    for(int i=1; i<=N; i++) {
        if(indegree[i] == 0) {
            parent = i;
            break;
        }
    }

    dfs(parent, 1);
    int ll = 0;
    int ans = 0;
    for(int i=1; i<=maxLevel; i++) {
        if(ans < level[i].second - level[i].first + 1) {
            ll = i;
            ans = level[i].second - level[i].first + 1;
        }
    }
    cout << ll << " " << ans;
}