#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> arr;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }

    sort(arr.begin(), arr.end());

    vector<int> vis(N, 0);

    int L, P;
    cin >> L >> P;
    int cur = 0;
    int cnt = 0;
    while(cur < L) {
        if(cur + P >= L) break;
        int maxOil = 0;
        int maxOilIdx = -1;
        int idx = 0;
        while(idx < arr.size() && arr[idx].first <= cur + P) {
            if(!vis[idx] && maxOil < arr[idx].second) {
                maxOil = arr[idx].second;
                maxOilIdx = idx;
            }
            ++idx;
        }
        if(maxOilIdx == -1) {
            cout << -1;
            return 0;
        }
        ++cnt;
        cur += P;
        P = maxOil;
        vis[maxOilIdx] = 1;
    }
    cout << cnt;
}