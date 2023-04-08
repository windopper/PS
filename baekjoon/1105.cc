#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string L, R;
    cin >> L >> R;
    if(L.size() != R.size()) {
        cout << 0;
        return 0;
    }
    else {
        int cnt = 0;
        for(int i=0; i<L.size(); i++) {
            if(L[i] == R[i]) ++cnt;
        }
        cout << cnt;
    }
}