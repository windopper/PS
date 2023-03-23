#include <bits/stdc++.h>

using namespace std;
int n;
int arr[2][100001];
int dp[3][100001];

int solve(int x, int st) {
    if(x >= n) return 0;
    int &ret = dp[st][x];
    if(ret != -1) return ret;

    if(st == 0) {
        ret = max(solve(x+1, 1), solve(x+2, 1)) + arr[st][x];
    }
    else {
        ret = max(solve(x+1, 0), solve(x+2, 0)) + arr[st][x];
    }

    return ret;
}

int solve_2(int x, int st) {
    if(x >= n) return 0;
    int &ret = dp[st][x];
    if(ret != -1) return ret;

    if(st == 1) {
        ret = max(solve(x+1, 0), solve(x+1, 2)) + arr[st][x];
    }
    else if(st == 0) {
        ret = max(solve(x+1, 1), solve(x+1, 2)) + arr[st][x];
    }
    else {
        ret = max(solve(x+1, 0), max(solve(x+1, 1), solve(x+1, 2)));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(; T>0; --T) {

        cin >> n;

        for(int i=0; i<3; i++) {
            for(int j=0; j<n; j++) {
                dp[i][j] = -1;
            }
        }

        for(int i=0; i<2; i++) {
            for(int j=0; j<n; j++) {
                cin >> arr[i][j];
            }
        }

        cout << max(solve_2(0, 2), max(solve_2(0, 0), solve_2(0, 1))) << "\n";
    }
}