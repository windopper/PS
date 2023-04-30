#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;
typedef long long ll;
typedef vector<int> vi;

struct Node {
    int mx = 0;
    int mn = INF;
    int cnt = 0;
};

Node f(Node& l, Node& r) {
    int mx, mn, cnt;
    mx = max(l.mx, r.mx);
    mn = min(l.mn, r.mn);
    cnt = 0;
    return {mx, mn, cnt};
}

Node tree[1 << 19];
int base = 1 << 18;

void update(int x, int v, int st) {
    x |= base;
    if(st == -1) {
        tree[x].cnt--;
        if(tree[x].cnt == 0) {
            tree[x].mx = 0;
            tree[x].mn = INF;
        }
    }
    else {
        tree[x].mx = max(tree[x].mx, v);
        tree[x].mn = min(tree[x].mn, v);
        tree[x].cnt++;
    }
    while(x >>= 1) {
        tree[x] = f(tree[x << 1], tree[x << 1 | 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> points;
    vector<int> yArr;
    vector<int> xArr;
    for(int i=0; i<N; i++) {
        int x1, x2, y1, y2;
        yArr.push_back(y1);
        yArr.push_back(y2);
        xArr.push_back(x1);
        xArr.push_back(x2);
        points.push_back({x1, y1, y2, 1});
        points.push_back({x2, y1, y2, -1});
    }
    
    sort(yArr.begin(), yArr.end());
    yArr.erase(unique(yArr.begin(), yArr.end()), yArr.end());
    sort(xArr.begin(), xArr.end());
    xArr.erase(unique(xArr.begin(), xArr.end(), xArr.end()));
    for(vector<int>& p : points) {
        int& x1 = p[0];
        int& y1 = p[1];
        int& y2 = p[2];
        x1 = lower_bound(xArr.begin(), xArr.end(), x1) - xArr.begin() + 1;
        y1 = lower_bound(yArr.begin(), yArr.end(), y1) - yArr.begin() + 1;
        y2 = lower_bound(yArr.begin(), yArr.end(), y2) - yArr.begin() + 1;
    }

    sort(points.begin(), points.end(), [](vi& a, vi& b) {
        return a[0] < b[0];
    });

    int beforeX = -1;
    ll ret = 0;
    for(vector<int> p : points) {
        int x1 = p[0];
        int y1 = p[1];
        int y2 = p[2];
        int st = p[3];

        if(beforeX == -1) {

        }
        else {

        }
    }

}