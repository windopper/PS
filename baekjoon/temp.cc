#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int K;
    cin >> K;
    for(int i=1; i<=K; i++) {
        int n;
        cin >> n;
        int maxV = 0;
        int minV = 100;
        int largestGap = 0;
        int before = -1;
        vector<int> arr;
        while(n--) {
            int t; cin >> t;
            arr.push_back(t);
        }
        sort(arr.begin(), arr.end(), greater<>());
        for(int t : arr) {
            if(before != -1) {
                largestGap = max(largestGap, abs(before - t));
            }
            before = t;
            maxV = max(maxV, t);
            minV = min(minV, t);
        }
        cout << "Class " << i << '\n';
        cout << "Max " << maxV << ", Min " << minV << ", Largest gap " << largestGap << '\n';
    }
}