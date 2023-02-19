#include <iostream>
#include <vector>

using namespace std;
int N, cnt = 1, temp = -1;
vector<int> A, pos, dp;

int lower_bound(int value) {
    int left = 0;
    int right = dp.size();
    int mid = right;
    while ( left < right) {
        mid = (left + right) / 2;
        if ( value > dp[mid] ) {
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
    A.resize(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    dp.push_back(A[0]);
    for(int i=1; i<N; i++) {
        if(dp.back() < A[i]) {
            dp.push_back(A[i]);
        }
        else {
            int idx = lower_bound(A[i]);
            dp[idx] = A[i];
        }
    }

    for(int i=0; i<dp.size(); i++) {
        cout << dp[i] << " ";
    }
}