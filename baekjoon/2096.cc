#include <bits/stdc++.h>

using namespace std;
int arr[3];
int minArr[3];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    memset(arr, 0, sizeof(arr));
    memset(minArr, 0, sizeof(minArr));
    for(int i=0; i<N; i++) {
        int t[3];
        cin >> t[0] >> t[1] >> t[2];
        int a = arr[0], b = arr[2];
        arr[0] = max(arr[0], arr[1]) + t[0];
        arr[2] = max(arr[1], arr[2]) + t[2];
        arr[1] = max(max(a, b), arr[1]) + t[1];
    
        a = minArr[0], b = minArr[2];
        minArr[0] = min(minArr[0], minArr[1]) + t[0];
        minArr[2] = min(minArr[1], minArr[2]) + t[2];
        minArr[1] = min(min(a, b), minArr[1]) + t[1];
    }

    int mxans = 0;
    int mnans = numeric_limits<int>::max();
    for(int i=0; i<3; i++) {
        mxans = max(mxans, arr[i]);
        mnans = min(mnans, minArr[i]);
    }
    cout << mxans << " " << mnans;
}