#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> arr;
vector<char> ans;
stack<int> q;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    arr.resize(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int idx = 0;
    bool NO = false;

    int cnt = 1;
    while(cnt < n+1) {
        while(cnt <= arr[idx]) {
            q.push(cnt);
            ans.push_back('+');
            cnt++;
        }
        while(!q.empty() && idx < n && q.top() == arr[idx]) {
            q.pop();
            ans.push_back('-');
            idx++;
        }
        if(!q.empty() && idx < n && q.top() > arr[idx]) {
            cout << "NO" << "\n";
            NO = true;
            break;
        }
    }

    if(!NO) {
        for(int i=0; i<ans.size(); i++) {
            cout << ans[i] << "\n";
        }
    }
}