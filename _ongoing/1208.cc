#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, S;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> S;
    vector<int> leftArr(N/2);
    vector<int> rightArr(N-N/2);
    for(int i=0; i<N; i++) {
        if(i<N/2) cin >> leftArr[i];
        else cin >> rightArr[i];
    }
    sort(rightArr.begin(), rightArr.end());
    int ans;
    for(int i=0; i<N/2; i++) {
        auto upperIdx = upper_bound(rightArr.begin(), rightArr.end(), S - leftArr[i]);
        auto lowerIdx = lower_bound(rightArr.begin(), rightArr.end(), S - leftArr[i]);
        ans += upperIdx - lowerIdx;
    }
    cout << ans;
}
