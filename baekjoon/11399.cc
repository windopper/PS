#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    int p[1001];
    for(int i=0; i<N; i++) cin >> p[i];
    sort(p, p+N);
    int csum = 0;
    int ans =0 ;
    for(int i=0; i<N; i++) {
        csum += p[i];
        ans += csum;
    }

    cout << ans;
}