#include <bits/stdc++.h>

using namespace std;
map<string, int> seq;
// 추월한 차량

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<string> A(N);
    vector<string> B(N);
    int idx = 0;
    for(int i=0; i<N; i++) {
        cin >> A[i];
        seq[A[i]] = idx++;
    }
    int ans = 0;
    for(int i=0; i<N; i++) {
        cin >> B[i];
    }

    for(int i=0; i<N; i++) {
        int num = seq[B[i]];
        for(int j=i; j<N; j++) {
            if(num > seq[B[j]]) {
                ++ans;
                break;
            }
        }
    }

    cout << ans;
}