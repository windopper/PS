#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int cur = 0;
    int num = 0;
    string snum = "";
    bool subtract = false;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '-') {
            num += stoi(snum);
            snum = "";

            if(subtract) cur -= num;
            else cur += num;
            subtract = true;
            num = 0;
        }
        else if(s[i] == '+') {
            num += stoi(snum);
            snum = "";
        }
        else {
            snum += s[i];
        }
    }

    num += stoi(snum);
    if(subtract) cur -= num;
    else cur += num;

    cout << cur;
}