#include <bits/stdc++.h>

using namespace std;
int arr[10001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    int ans = 0;
    for(int i=0; i<N-2; i++) {
        int minValue = 10001;
        for(int j=0; j<3; j++) {
            minValue = min(minValue, arr[i+j]);
        }
        ans += minValue * 7;
        for(int j=0; j<3; j++) {
            arr[i+j] -= minValue;
        }
    }

    for(int i=0; i<N-1; i++) {
        int minValue = 10001;
        for(int j=0; j<2; j++) {
            minValue = min(minValue, arr[i+j]);
        }
        ans += minValue * 5;
        for(int j=0; j<2; j++) {
            arr[i+j] -= minValue;
        }
    }

    for(int i=0; i<N; i++) {
        ans += arr[i] * 3;
    }

    cout << ans;
}