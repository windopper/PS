#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for(; t>0; t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        for(int i=0; i<m; i++) {
            cin >> b[i];
        }
        sort(a, a+n);
        sort(b, b+m);
        int total = 0;
        int cnt = 0;
        int tmp = 0;
        for(int i=0; i<n; i++) {
            bool isBreak = false;
            for(int j=tmp; j<m; j++) {
                if(a[i] <= b[j]) {
                    tmp = j;
                    total += cnt;
                    isBreak = true;
                    break;
                }
                cnt += 1;
            }
            if (!isBreak) tmp = m;
            if(tmp == m) {
                total += cnt;
            }
        }
        cout << total << "\n";
    }
}