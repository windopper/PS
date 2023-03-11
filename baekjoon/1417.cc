#include <bits/stdc++.h>

using namespace std;
int N;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    vector<int> arr(N);
    int total = 0;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    while(true) {
        int cur = arr[0];
        int maxIdx = -1;
        int maxCnt = -1;
        for(int i=1; i<N; i++) {
            if(maxCnt < arr[i]) {
                maxIdx = i;
                maxCnt = arr[i];
            }
        }
        if(maxCnt < cur) break;
        arr[0] = cur + 1;
        arr[maxIdx] -= 1;
        ++ans;

    }

    cout << ans;
}