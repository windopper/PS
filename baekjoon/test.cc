#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(true) {
        int arr[3] = {0, };
        for(int i=0; i<3; i++) cin >> arr[i];
        if(arr[0] == 0) break;
        int maxIndex;
        int maxValue = 0;
        for(int i=0; i<3; i++) {
            if(maxValue < arr[i]) {
                maxIndex = i;
                maxValue = arr[i];
            }
        }
        int a2b2 = 0;
        int c2 = maxValue * maxValue;
        for(int i=0; i<3; i++) {
            if(i == maxIndex) continue;
            a2b2 += arr[i] * arr[i];
        }
        if(a2b2 == c2) cout << "right";
        else cout << "wrong";
        cout << "\n";
    }
}