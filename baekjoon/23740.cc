#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> arr(N, vector<int>(3));
    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    sort(arr.begin(), arr.end());
    int s = arr[0][0];
    int e = arr[0][1];
    int cost = arr[0][2];
    vector<vector<int>> ans;
    for (int i = 1; i < N; i++) {
        if (e >= arr[i][0]) {
            e = max(e, arr[i][1]);
            cost = min(cost, arr[i][2]);
        } else {
            ans.push_back({s, e, cost});
            s = arr[i][0];
            e = arr[i][1];
            cost = arr[i][2];
        }
    }
    ans.push_back({s, e, cost});
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (vector<int> vec : ans) {
        cout << vec[0] << " " << vec[1] << " " << vec[2] << "\n";
    }
}