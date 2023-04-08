#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<pair<int, int>> arr;
    for(int i=0; i<N; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end());
    priority_queue<int, vector<int>, greater<>> pq;
    int ans = 0;
    for(int i=0; i<N; i++) {
        if(pq.size() < arr[i].first) {
            ans += arr[i].second;
            pq.push(arr[i].second);
        }
        else if(pq.top() < arr[i].second) {
            ans -= pq.top();
            pq.pop();
            ans += arr[i].second;
            pq.push(arr[i].second);
        }
    }
    cout << ans;
}