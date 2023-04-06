#include <bits/stdc++.h>

using namespace std;
vector<int> match[1001];
vector<int> aMatch;
vector<int> bMatch;

int dis[1001];

int dfs(int cur) {
    if(dis[cur]) return false;
    dis[cur] = true;
    for(int next : match[cur]) {
        if(bMatch[next] == -1 || dfs(bMatch[next])) {
            aMatch[cur] = next;
            bMatch[next] = cur;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        int t;
        cin >> t;
        for(int j=0; j<t; j++) {
            int x;
            cin >> x;
            match[i+1].push_back(x);
        }
    }

    aMatch.assign(N+1, -1);
    bMatch.assign(M+1, -1);
    int cnt = 0;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<2; j++) {
            memset(dis, 0, sizeof(dis));
            if(dfs(i)) ++cnt;
        }
    }
    cout << cnt;
}