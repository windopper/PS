#include <bits/stdc++.h>

using namespace std;
int N;
priority_queue<pair<int, int>> pq;
vector<int> arr;
vector<int> target;
vector<int> L;
vector<int> dp;
vector<int>::iterator iter;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    dp.resize(N, 1);
    for(int i=0; i<N; i++) {
        int a, b;
        cin >> a >> b;
        pq.push({-a, b});
    }
    while(!pq.empty()) {
        arr.push_back(-pq.top().first);
        target.push_back(pq.top().second);
        pq.pop();
    }
    L.push_back(target[0]);
    dp[0] = 1;
    for(int i=1; i<N; i++) {
        if(L[L.size()-1] < target[i]) {
            L.push_back(target[i]);
            dp[i] = L.size();
        }
        else {
            iter = lower_bound(L.begin(), L.end(), target[i]);
            *iter = target[i];
            dp[i] = iter-L.begin()+1;
        }
    }

    // for(int i=0; i<dp.size(); i++) {
    //     cout << dp[i] << " ";
    // }

    int idx = L.size();
    vector<int> ans;
    for(int i=dp.size()-1; i>=0; i--) {
        if(dp[i] == idx) {
            --idx;
        }
        else {
            ans.push_back(arr[i]);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}