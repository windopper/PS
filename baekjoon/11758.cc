#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pair<int, int> p[3];
    for(int i=0; i<3; i++) {
        int x,y;
        cin >> x >> y;
        p[i] = {x, y};
    }

    pair<int, int> p12 = {p[1].first - p[0].first, p[1].second - p[0].second};
    pair<int, int> p23 = {p[2].first - p[1].first, p[2].second - p[1].second};
    int ccw = p12.first * p23.second - p23.first * p12.second;
    if(ccw > 0) cout << 1;
    else if(ccw < 0) cout << -1;
    else cout << 0;
}