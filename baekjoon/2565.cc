#include <bits/stdc++.h>

using namespace std;
int N;
vector<int> arr;
const int INF = 987654321;
int dp[201];

int solve(int cur) {
    if(cur > N) {
        bool dup = false;
        int maxValue = 0;

        for(int i=1; i<=N; i++) {
            if(arr[i] == -1) continue;
            if(maxValue > arr[i]) {
                dup = true;
                break;
            }
            else {
                maxValue = arr[i];
            }
        }
        //cout << "jump";
        if(!dup) {
            return 0;
        }

        return INF;
    }
    //int &ret = dp[cur];
    //if(ret != -1) return ret;
    int ret = INF;
    for(int i=1; i<=cur; i++) {
        if(arr[i] == -1) continue;
        if(arr[i] > arr[cur]) {
            int temp = arr[i];
            arr[i] = -1;
            ret = min(ret, solve(cur+1) + 1);
            arr[i] = temp;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    arr.resize(N+1);
    for(int i=0; i<N; i++) {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(1);
}