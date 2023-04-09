#include <bits/stdc++.h>

using namespace std;
vector<vector<long long>> sharks;
vector<vector<int>> adj;
int dis[51];
int aMatch[51];
int bMatch[51];
int N;

bool canEat(vector<long long>& a, vector<long long>& b) {
    return (a[0]>=b[0]) && (a[1]>=b[1]) && (a[2]>=b[2]);
}

bool dfs(int cur) {
    if(dis[cur]) return false;
    dis[cur] = 1;
    for(int next : adj[cur]) {
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
    cin >> N;
    for(int i=0; i<N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sharks.push_back({a, b, c});
    }

    adj.resize(N);
    for(int i=0; i<N-1; i++) {
        for(int j=i+1; j<N; j++) {
            if(canEat(sharks[i], sharks[j])) {
                adj[i].push_back(j);
            }
            else if(canEat(sharks[j], sharks[i])) {
                adj[j].push_back(i);
            }
        }
    }

    memset(aMatch, -1, sizeof(aMatch));
    memset(bMatch, -1, sizeof(bMatch));
    int ans = N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<2; j++) {
            memset(dis, 0, sizeof(dis));
            if(dfs(i)) --ans;
        }
    }
    cout << ans;
}