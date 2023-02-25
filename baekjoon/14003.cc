#include <bits/stdc++.h>

using namespace std;
int N;
int pos_tmp = 0, idx = 0;
vector<int> A, pos, dp;
vector<int>::iterator iter;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    A.resize(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    dp.push_back(A[0]);
    pos.push_back(1);
    for(int i=1; i<N; i++) {
        if(dp.back() < A[i]) {
            dp.push_back(A[i]);
            pos.push_back(dp.size());
        }
        else {
            iter = lower_bound(dp.begin(), dp.end(), A[i]);
            *iter = A[i];
            pos.push_back(iter-dp.begin() + 1);
        }
        if(pos[i] > pos_tmp) {
            pos_tmp = pos[i];
            idx = i;
        }
    }

    cout << dp.size() << "\n";
    stack<int> ans;
    ans.push(A[idx]);
    for(int i=idx-1; i>=0; i--) {
        if(A[i]<A[idx] && pos[i]+1 == pos[idx]) {
            idx = i;
            ans.push(A[i]);
        }
    }
    while(!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
}