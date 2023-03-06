#include <bits/stdc++.h>

using namespace std;
const int MOD = 1000000000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    int s = -MOD;
    int e = -MOD;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int m = arr[i].first;
        int n = arr[i].second;
        if (e >= m) {
            e = max(e, n);
        } else {
            ans += e - s;
            s = m;
            e = n;
        }
    }
    ans += e - s;
    cout << ans;
}