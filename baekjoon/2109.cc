#include <bits/stdc++.h>
#include <functional>

using namespace std;
typedef pair<int, int> pii;
vector<pii> arr;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int d, p;
        cin >> p >> d;
        arr.push_back({d, p});
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    sort(arr.begin(), arr.end());
    int ans = 0;
    for(int i=0; i<n; i++) {
        pq.push(arr[i].second);
        ans += arr[i].second;
        if(pq.size() > arr[i].first) {
            ans -= pq.top();
            pq.pop();
        }
    }
    cout << ans;
}