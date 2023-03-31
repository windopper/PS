#include <bits/stdc++.h>

using namespace std;

int ccw(int x1, int y1, int x2, int y2) {
    return x1 * y2 - y1 * x2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

    if(x1>x2) swap(x1, x2);
    if(y1>y2) swap(y1, y2);
    if(x3>x4) swap(x3, x4);
    if(y3>y4) swap(y3, y4);

    int ret = ccw(x2-x1, y2-y1, x3-x1, y3-y1) * ccw(x2-x1, y2-y1, x4-x1, y4-y1);
    cout << ret;
}