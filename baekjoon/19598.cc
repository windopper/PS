#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<pair<int, int>> arr;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, 1});
        arr.push_back({b, -1});
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < 2 * N; i++) {
        cur += arr[i].second;
        ans = max(ans, cur);
    }
    cout << ans;
}