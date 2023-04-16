#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int e, s, m;
    cin >> e >> s >> m;
    int a = 1, b = 1, c = 1;
    int cnt = 1;
    while(e != a || s != b || m != c) {
        ++a;
        ++b;
        ++c;
        ++cnt;
        if(a == 16) a = 1;
        if(b == 29) b = 1;
        if(c == 20) c = 1;
    }

    cout << cnt;
}