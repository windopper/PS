#include <bits/stdc++.h>

using namespace std;
int N, M, H;
vector<vector<int>> arr;
int ans = 987654321;

bool check() {
    for(int i=1; i<=N; i++) {
        int cur = i;
        int loc = 1;
        while(loc <= H) {
            if(arr[loc][cur]) ++cur;
            else if(cur > 1 && arr[loc][cur-1]) --cur;
            ++loc;
        }
        if(i != cur) return false;
    }

    return true;
}

void solve(int cnt, int curi) {
    if(cnt > 3 || cnt >= ans) {
        return;
    }
    if(check()) {
        ans = min(ans, cnt);
        return;
    }
    for(int i=curi; i<=H; i++) {
        for(int j=1; j<=N-1; j++) {
            if(arr[i][j]) continue;
            arr[i][j] = 1;
            solve(cnt + 1, i);
            arr[i][j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> H;
    arr.resize(H+1, vector<int>(N+1, 0));
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        // 가로선위치, 세로선위치
    }

    solve(0, 1);
    
    if(ans == 987654321) ans = -1;
    cout << ans;
}