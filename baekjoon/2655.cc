#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int N;
vector<vector<int>> arr;
int dp[101];
int tracedp[101];

bool compare(vi& a, vi& b) {
    return a[0] != b[0] ? a[0] > b[0] : a[2] > b[2];
}

int solve(int cur) {
    if(cur > N) return 0;
    int &ret = dp[cur];
    if(ret != -1) return ret;
    ret = 0;
    int curWeight = arr[cur][2];
    int bestNext = 0;
    for(int i=cur+1; i<=N; i++) {
        if(cur == 0 || curWeight > arr[i][2]) {
            int temp = solve(i) + arr[i][1];
            if(ret < temp) {
                ret = temp;
                bestNext = i;
            }
        }
    }
    tracedp[cur] = bestNext;
    return ret;
}

vector<int> ans;
int cnt = 0;
void track(int cur) {
    if(cur != 0) {
        ans.push_back(cur);
        ++cnt;
    }
    int next = tracedp[cur];
    if(next != 0) track(next);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    arr.assign(N+1, vector<int>(4, 0));
    memset(tracedp, 0, sizeof(tracedp));
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<=N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        arr[i][3] = i;
    }
    arr[0][0] = arr[0][2] = 10001;
    arr[0][1] = 0;
    arr[0][3] = 0;
    sort(arr.begin(), arr.end(), compare);
    solve(0);
    track(0);
    cout << cnt << '\n';
    for(int i=ans.size()-1; i>=0; --i) cout << arr[ans[i]][3] << "\n";
}