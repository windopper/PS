#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    if(N % 2 == 1) cout << arr[N/2];
    else cout << arr[N/2-1];
}