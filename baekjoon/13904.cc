#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
vector<pii> arr;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int d, w;
        cin >> d >> w;
        arr.push_back({d, w});
    }
    priority_queue<int> pq;
    sort(arr.begin(), arr.end());

    int ans = 0;
    for(int i=0; i<N; i++) {
        ans += arr[i].second;
        pq.push(-arr[i].second);
        if(pq.size() > arr[i].first) {
            ans -= -pq.top();
            pq.pop();
        }
    }
    
    cout << ans;
}