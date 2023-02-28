#include <bits/stdc++.h>

using namespace std;
string s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    int cnt = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'X') {
            ++cnt;
        }

        if(cnt == 4) {
            for(int j=i; j>i-4; j--) {
                s[j] = 'A';
            }
            cnt = 0;
            continue;
        }
        else if(i+1 >= s.size() || s[i+1] == '.') {
            if(cnt == 2) {
                for(int j=i; j>i-2; --j) {
                    s[j] = 'B';
                }
            }
            else if(cnt != 0) {
                cout << -1;
                return 0;
            }
            cnt = 0;
        }
    }

    cout << s;

}