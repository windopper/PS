#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> arr(11, vector<int>(11));

int dfs(vector<bool>& visited, int ret, int pos) {
    if(pos == 11) return ret;
    int ans = 0;
    for(int i=0; i<11; i++) {
        if(visited[i]) continue;
        if(arr[i][pos] == 0) continue;
        visited[i] = true;
        ans = max(ans, dfs(visited, ret + arr[i][pos], pos + 1));
        visited[i] = false;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int C;
    cin >> C;
    for(; C>0; C--) {
        for(int i=0; i<11; i++) {
            for(int j=0; j<11; j++) {
                cin >> arr[i][j];
            }
        }

        vector<bool> visited(11, false);
        int pos = 0;
        int ans = 0;
        for(int i=0; i<11; i++) {
            if(arr[i][pos] == 0) continue;
            visited[i] = true;
            ans = max(ans, dfs(visited, arr[i][pos], pos + 1));
            visited[i] = false;
        }

        cout << ans << "\n";
    }
}