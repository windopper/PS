#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> arr;
int dp[20][200001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    arr.resize(n+1);
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        dp[0][i] = arr[i];
    }
    for(int j=1; j<20; j++) {
        for(int i=1; i<=n; i++) {
            dp[j][i] = dp[j-1][dp[j-1][i]];
        }
    }
    cin >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        for(int i=0; a != 0; i++) {
            if(a % 2 == 1) b = dp[i][b];
            a /= 2;
        }
        cout << b << '\n';
    }

}