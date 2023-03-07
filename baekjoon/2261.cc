#include <bits/stdc++.h>

using namespace std;

int getDist(pair<int, int> c1, pair<int, int> c2) { return pow(c2.first - c1.first, 2) + pow(c2.second - c1.second, 2); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    // x좌표로 정렬
    int ans = getDist(arr[0], arr[1]);
    // 처음 두 점 거리
    for (int i = 2; i < n; i++) {
    }
}