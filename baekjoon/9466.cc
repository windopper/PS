#include <bits/stdc++.h>

using namespace std;
int made[100001];
int arr[100001];

bool dfs(int cur, int target) {
    if(made[cur]) return false;
    if(cur == target) {
        return true;
    }
    if(dfs(arr[cur], target)) {
        made[cur] = 1;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(; T>0; --T) {
        int n;
        cin >> n;
        memset(made, 0, sizeof(made));
        memset(arr, 0, sizeof(arr));
        for(int i=1; i<n+1; i++) {
            cin >> arr[i];
        }

        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(made[i]) continue;
            if(dfs(arr[i], i)) {
                made[i] = 1;
            }
        }

        for(int i=1; i<=n; i++) {
            if(!made[i]) ++ans;
        }

        cout << ans << "\n";
    }
}