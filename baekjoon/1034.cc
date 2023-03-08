#include <bits/stdc++.h>

using namespace std;
int N, M, K;
vector<vector<int>> arr(50, vector<int>(50));
int ans = 0;

void dfs(vector<vector<int>>& arr, int t, int k) {
    if (k == K) {
        int ret = 0;
        for (int i = 0; i < N; i++) {
            bool full = true;
            for (int j = 0; j < M; j++) {
                if (!arr[i][j]) {
                    full = false;
                    break;
                }
            }
            if (full) ++ret;
        }
        ans = max(ans, ret);
        return;
    }

    for (int i = t; i < M; i++) {
        for (int j = 0; j < N; j++) {
            arr[j][i] = 1 - arr[j][i];
        }
        dfs(arr, i, k + 1);
        for (int j = 0; j < N; j++) {
            arr[j][i] = 1 - arr[j][i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) arr[i][j] = s[j] - '0';
    }

    cin >> K;
    int Mpow = pow(2, M);
    if (K < Mpow && K > M) {
        while (K < Mpow && K > M) {
            K = Mpow - K;
        }
    } else if (K >= pow(2, M)) {
        if (K % 2 == 0) {
            K = K % M;
        } else {
            K = K % M + M;
        }
    } else if (K <= M) {
    }

    dfs(arr, 0, 0);
    cout << ans;
}