#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> arr(6);
    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        ans += arr[i] * N * N;
    }

    cout << ans;
}