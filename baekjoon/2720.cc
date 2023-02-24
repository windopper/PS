#include <bits/stdc++.h>

using namespace std;
int m[4] = {25, 10, 5, 1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(; T>0; T--) {
        int C;
        cin >> C;
        int ans[4] = {0, };
        for(int i=0; i<4; i++) {
            ans[i] = C / m[i];
            C %= m[i];
        }
        for(int i=0; i<4; i++) cout << ans[i] << " ";
        cout << "\n";
    }
}