#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ans = 0;
    string s;
    cin >> s;
    int N;
    cin >> N;
    while(N--) {
        string c;
        cin >> c;
        string cc;
        for(int j=0; j<11; j++) cc += c;
        int idx = 0;
        if(cc.find(s) != string::npos) ++ans;
    }

    cout << ans;
}