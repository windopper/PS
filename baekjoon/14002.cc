#include <iostream>
#include <vector>

using namespace std;

int N, cnt = 1, idx = 0;
vector<int> A, dp, res;

int main() {
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> N;
    A.resize(N); dp.resize(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    
    dp[0] = 1;
    for(int i=1; i<N; i++) {
        for(int j=0; j<i; j++) {
            if (A[j] < A[i]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        if (dp[i] == 0) {
            dp[i] = 1;
        }
        if (dp[i] > cnt) {
            cnt = dp[i];
            idx = i;
        }
    }

    cout << cnt << "\n";

    for(int i=idx; i>=0; i--) {
        if(cnt == dp[i]) {
            res.push_back(A[i]);
            cnt--;
        }
    }

    for(int i=res.size() - 1; i>=0; i--) {
        cout << res[i];
        if (i != 0) { cout << " "; }
    }
    
}