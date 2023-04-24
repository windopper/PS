#include <bits/stdc++.h>

using namespace std;
bool isPrime[2002];
vector<vector<int>> adj;
int aMatch[51];
int bMatch[51];
int dis[51];

bool dfs(int cur) {
    if(dis[cur]) return false;
    dis[cur] = true;
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
    int N;
    cin >> N;
    for(int i=2; i<=2001; i++) {
        isPrime[i] = true;
    }

    for(int i=2; i<=sqrt(2001); i++) {
        if(!isPrime[i]) continue;
        for(int j=i*i; j<=2001; j+=i) {
            isPrime[j] = false;
        }
    }
    vector<pair<int, int>> arr(N);
    for(int i=0; i<N; i++) {
        int t;
        cin >> t;
        arr[i] = {t, i};
    }

    sort(arr.begin(), arr.end());

    int firstElementIdx = -1;
    for(int i=0; i<N; i++) {
        if(arr[i].second == 0) {
            firstElementIdx = i;
            break;
        }
    }

    adj.resize(N+1);
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            if(isPrime[arr[i].first+arr[j].first]) {
                cout << i << " " << j << '\n';
                adj[i].push_back(j);
            }
        }
    }

    memset(aMatch, -1, sizeof(aMatch));
    memset(bMatch, -1, sizeof(bMatch));
    set<int> ans;
    for(int i=0; i<N; i++) {
        memset(dis, 0, sizeof(dis));
        dfs(i);
    }

    for(int next : adj[firstElementIdx]) {
        memset(dis, 0, sizeof(dis));
        dis[firstElementIdx] = true;
        if(dfs(bMatch[next])) {
            ans.insert(next);
        }
    }

    for(set<int>::iterator it=ans.begin(); it!=ans.end(); it++) {
        cout << *it << " ";
    }
    if(ans.empty()) cout << -1;
}