#include <bits/stdc++.h>

using namespace std;
bool isPrime[2002];
vector<vector<int>> adj;
vector<pair<int, int>> arr;
int bMatch[1001];
int dis[1001];

bool dfs(int cur) {
    if(dis[cur]) return false;
    dis[cur] = true;
    for(int next : adj[cur]) {
        if(bMatch[next] == -1 || dfs(bMatch[next])) {
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
    adj.resize(1001);
    for(int i=2; i<=2001; i++) {
        isPrime[i] = true;
    }

    for(int i=2; i<=sqrt(2001); i++) {
        if(!isPrime[i]) continue;
        for(int j=i*i; j<=2001; j+=i) {
            isPrime[j] = false;
        }
    }
    
    bool isFirstEven = false;
    vector<int> arr1;
    vector<int> arr2;
    for(int i=0; i<N; i++) {
        int t;
        cin >> t;
        if(i == 0) {
            if(t % 2 == 1) isFirstEven = false;
            else isFirstEven = true;
        }

        if(isFirstEven) {
            // arr1 짝수
            if(t % 2 == 0) {
                arr1.push_back(t);
            }
            else {
                arr2.push_back(t);
            }
        }
        else {
            // arr1 홀수
            if(t % 2 == 0) {
                arr2.push_back(t);
            }
            else {
                arr1.push_back(t);
            }
        }
    }

    if(arr1.size() != arr2.size()) {
        cout << -1;
        return 0;
    }

    for(int i=0; i<arr1.size(); i++) {
        for(int j=0; j<arr2.size(); j++) {
            if(isPrime[arr1[i] + arr2[j]]) {
                adj[arr1[i]].push_back(arr2[j]);
            }
        }
    }

    vector<int> ans;
    for(int next : adj[arr1[0]]) {
        memset(bMatch, -1, sizeof(bMatch));
        bMatch[next] = arr1[0];
        int cnt = 0;
        for(int i=0; i<arr1.size(); i++) {
            if(i == 0) continue;
            memset(dis, 0, sizeof(dis));
            dis[next] = 1;
            dis[arr1[0]] = 1;
            if(dfs(arr1[i])) ++cnt;
        }
        if(cnt == arr1.size()-1) ans.push_back(next);
    }

    sort(ans.begin(), ans.end());
    for(int cur : ans) cout << cur << " ";
    if(ans.empty()) cout << -1;
}