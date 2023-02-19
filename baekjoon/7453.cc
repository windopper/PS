/*
    MITM 알고리즘
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    vector<int> A(n), B(n), C(n), D(n);
    for(int i=0; i<n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    vector<int> AB;
    vector<int> CD;
    // 벡터를 두개로 쪼개볼까?
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());
    long long ans = 0;
    for(int i=0; i<AB.size(); i++) {
        int lower_idx = lower_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
        int upper_idx = upper_bound(CD.begin(), CD.end(), -AB[i]) - CD.begin();
        ans += upper_idx - lower_idx;
    }
    cout << ans;

}