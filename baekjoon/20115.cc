#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    int arr[100001];
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
    double ans = arr[N-1];
    for(int i=0; i<N-1; i++) {
        ans += (double)arr[i] / 2;
    }
    cout << ans;
}