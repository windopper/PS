#include <bits/stdc++.h>

using namespace std;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        arr.push_back({b, a});
    }
    int d;
    cin >> d;
    sort(arr.begin(), arr.end());
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].first - arr[i].second > d) continue;
        // 기준보다 길면 볼 필요도 없다.
        else
            pq.push(-arr[i].second);
        // 출발위치를 우선순위 큐에 넣어볼까

        while (!pq.empty()) {
            if (-pq.top() < arr[i].first - d) pq.pop();
            // 가장 작은 출발위치와 현재 선분의 도착 위치가 기준보다 길면
            // 없애버리자
            else {
                ans = max(ans, (int)pq.size());
                break;
            }
        }
    }
    cout << ans;
}