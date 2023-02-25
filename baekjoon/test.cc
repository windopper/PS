#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int i, m = 0, idx, cnt = 1;
    while(cnt < 10) {
        cin >> i;
        if(i > m) {
            idx = cnt;
            m = i;
        }
        ++cnt;
    }
    cout << m << "\n" << idx;
}