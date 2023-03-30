#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> to[101][101];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K, R;
    cin >> N >> K >> R;
    for(int i=0; i<R; i++) {
        int r, c, r_, c_;
        cin >> r >> c >> r_ >> c_;
        to[r][c].push_back({r_, c_});
    }

    vector<pair<int, int>> cows;

    for(int i=0; i<K; i++) {
        int r, c;
        cin >> r >> c;
        cows.push_back({r, c});
    }

    int ans = 0;

    for(int i=0; i<K; i++) {
        int r = cows[i].first;
        int c = cows[i].second;
        for(int j=0; j<K; j++) {
            if(i == j) continue;
            int r_ = cows[j].first;
            int c_ = cows[j].second;
            for(int k=0; k<to[r][c].size(); k++) {
                int r__ = to[r][c][k].first;
                int c__ = to[r][c][k].second;

                if(r_ == r__ && c_ == c__) ++ans;
            }
        }
    }

    cout << ans;
}