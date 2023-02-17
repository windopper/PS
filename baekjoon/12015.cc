#include <iostream>
#include <vector>
using namespace std;
int N;
int cnt = 1;
vector<int> arr, dp;

int lower_bound(int value) {
    int left = 0;
    int right = dp.size() - 1;
    int mid = ( right + left ) / 2;
    while (left < right) {
        int mid = ( right + left ) / 2;
        if (value > dp[mid]) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return right;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    arr.resize(N+1);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    dp.push_back(arr[0]);
    for(int i=1; i<N; i++) {
        if (dp.back() < arr[i]) {
            dp.push_back(arr[i]);
            cnt++;
        }
        else {
            int idx = lower_bound(arr[i]);
            dp[idx] = arr[i];
        }
    }
    cout << cnt;
}