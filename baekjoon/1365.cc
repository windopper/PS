#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<int> arr(N+1);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    int i=0;
    vector<int> dp;
    while(i<N) {
        if(dp.empty() || dp.back() < arr[i]) {
            dp.push_back(arr[i]);
        }
        else {
            int idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[idx] = arr[i];
        }
        ++i;
    }

    cout << N - dp.size();
}