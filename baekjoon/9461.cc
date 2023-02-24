#include <bits/stdc++.h>

using namespace std;
int T, N;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    long long arr[101];
    arr[1] = 1; arr[2] = 1; arr[3] = 1; arr[4] = 2;
    arr[5] = 2; arr[6] = 3; arr[7] = 4; arr[8] = 5;
    arr[9] = 7; arr[10] = 9;
    for(; T>0; T--) {
        cin >> N;
        if(N>10) {
            for(int i=11; i<=N; i++) {
                arr[i] = arr[i-1] + arr[i-5];
            }
        }
        cout << arr[N] << "\n";
    }
}