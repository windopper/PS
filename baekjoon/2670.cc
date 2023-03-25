#include <bits/stdc++.h>

using namespace std;
int N;
double arr[10001];
double dp[10001];

double solve(int cur) {
    if(cur == N-1) return arr[cur];
    double &ret = dp[cur];
    if(ret != 0) return ret;
    ret = max(solve(cur+1) * arr[cur], arr[cur]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    double ans = 0;
    for(int i=0; i<N; i++) {
        ans = max(ans, solve(i));
    }
    cout << fixed, cout.precision(3);
    cout << round(ans * 1000) / 1000;
}