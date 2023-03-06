#include <bits/stdc++.h>

using namespace std;
int N, K;
vector<int> arr, diff;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    arr.resize(N);
    diff.resize(N);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    for(int i=1; i<N; ++i) diff[i-1] = arr[i] - arr[i-1];
    sort(diff.begin(), diff.end());
    for(int i=0; i<N-K+1; i++) {
        ans += diff[i];     
    }
    cout << ans;
}