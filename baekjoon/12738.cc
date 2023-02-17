#include <iostream>
#include <vector>

using namespace std;

int N, cnt = 1;
vector<int> A, dp;

int lower_bound(int value) {
    int left = 0;
    int right = dp.size() - 1;
    int mid = right;
    while (left < right) {
        mid = (left + right) / 2;
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
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> N;
    A.resize(N + 1);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    dp.push_back(A[0]);
    for(int i=1; i<N; i++) {
        if (dp.back() < A[i]) {
            dp.push_back(A[i]);
            cnt++;
        }
        else {
            int idx = lower_bound(A[i]);
            dp[idx] = A[i];
        }
    }
    cout << cnt;
}