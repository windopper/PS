#include <bits/stdc++.h>

using namespace std;
int N, K;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    arr.resize(N);
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int ans = arr[N-1] - arr[0];
    for(int i=N-1; i>0; --i) {
        arr[i] = arr[i] - arr[i-1];
    }
    arr[0] = 0;
    sort(arr.begin(), arr.end());
    for(int i=N-1; i>N-K; --i) ans -= arr[i];
    cout << ans;
}