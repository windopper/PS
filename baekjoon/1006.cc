#include <bits/stdc++.h>

using namespace std;
int dp[20001][3][4];
int arr[10001][2];
int N, W;

// status 0 -> 아무것도 안채움
// 1 -> 첫번째 셀 채움
// 2 -> 두번째 셀 채움
int solve(int cur, int status, int firstStatus) {
    if (cur >= N) return 0;
    int &ret = dp[cur][status][firstStatus];
    if (ret != -1) return ret;
    ret = 20000;

    // 상, 하 하나씩
    if (status == 0) {
        if (cur + 1 < N || (cur == N - 1 && (firstStatus == 0))) {
            ret = min(ret, solve(cur + 1, 0, firstStatus) + 2);
        }
    }
    // 상, 하 중 빈거 하나 채우기
    if (status == 1 || status == 2) {
        if (cur + 1 < N || (cur == N - 1 && (firstStatus == 1 || firstStatus == 2))) {
            ret = min(ret, solve(cur + 1, 0, firstStatus) + 1);
        }
    }
    // 상, 하가 모두 비어있을 때 비교후 한번에 채우기
    if (status == 0 && arr[cur][0] + arr[cur][1] <= W) {
        if (cur + 1 < N || (cur == N - 1 && (firstStatus == 0))) {
            ret = min(ret, solve(cur + 1, 0, firstStatus) + 1);
        }
    }
    // 윗 줄 2칸 채우기
    if (cur + 1 < N && arr[cur][0] + arr[cur + 1][0] <= W) {
        // 마지막 줄일 때
        if (cur + 1 < N-1 || (cur == N - 2 && (firstStatus == 0 || firstStatus == 2))) {
            // 아래 줄도 비어있으면 한칸 채우기
            if (status == 0) {
                if(cur == N-2 && firstStatus == 0) {
                    ret = min(ret, solve(cur + 1, 1, firstStatus) + 2);
                }
                else if(cur + 1 < N-1) {
                    ret = min(ret, solve(cur + 1, 1, firstStatus) + 2);
                }
            }
            // 아니면 윗 줄 2칸만 채우기
            else if (status == 2)
                ret = min(ret, solve(cur + 1, 1, firstStatus) + 1);
        }
    }
    // 반대줄도 채우기
    if (cur + 1 < N && arr[cur][1] + arr[cur + 1][1] <= W) {
        if (cur + 1 < N-1 || (cur == N - 2 && (firstStatus == 0 || firstStatus == 1))) {
            if (status == 0) {
                if(cur == N-2 && firstStatus == 0) {
                    ret = min(ret, solve(cur + 1, 2, firstStatus) + 2);
                }
                else if(cur + 1 < N-1) {
                    ret = min(ret, solve(cur + 1, 2, firstStatus) + 2);
                }
            } else if (status == 1) {
                ret = min(ret, solve(cur + 1, 2, firstStatus) + 1);
            }
        }
    }

    if (status == 0 && cur + 1 < N && arr[cur][1] + arr[cur + 1][1] <= W && arr[cur][0] + arr[cur + 1][0] <= W) {
        if (cur + 1 < N-1 || (cur == N - 2 && (firstStatus == 0))) {
            ret = min(ret, solve(cur + 2, 0, firstStatus) + 2);
        }
    }

    //cout << cur << " " << ret << "\n";
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (; T > 0; --T) {
        cin >> N >> W;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[j][i];
            }
        }

        int ans = 20000;
        if(arr[0][0] + arr[N-1][0] <= W) {
            ans = min(ans, solve(0, 1, 1) + 1);
        }
        if(arr[0][1] + arr[N-1][1] <= W) {
            ans = min(ans, solve(0, 2, 2) + 1);
        }
        if(arr[0][0] + arr[N-1][0] <= W && arr[0][1] + arr[N-1][1] <= W) {
            ans = min(ans, solve(1, 0, 3) + 2);
        }
        ans = min(ans, solve(0, 0, 0));
        cout << ans << "\n";
    }
}