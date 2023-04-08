#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int maxArr[4] = {0, };
    int minArr[4];
    for(int i=0 ;i<4; i++) {
        minArr[i] = 255;
    }
    vector<vector<int>> arr;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        vector<int> bits;
        int loc = 0;
        for(int i=0; i<4; i++) {
            if(loc >= s.size()) {
                minArr[i] = 0;
                maxArr[i] = 0;
                break;
            }
            string ss;
            int sub = 0;
            while(loc+sub < s.size() && s[loc+sub] != '.') {
                ++sub;
            }
            ss = s.substr(loc, sub);
            loc = loc + sub + 1;
            int t = stoi(ss);
            minArr[i] = min(minArr[i], t);
            maxArr[i] = max(maxArr[i], t);
            bits.push_back(t);
        }
        arr.push_back(bits);
    }

    int masks[4] = {0, };
    int maxMask = 0;
    for(int i=0; i<4; i++) {
        if(maxMask > 0) {
            masks[i] = pow(2, 8);
            continue;
        }
        for(int j=0; j<=8; j++) {
            if(maxArr[i] - minArr[i] < pow(2, j)) {
                masks[i] = pow(2, j);
                maxMask = max(maxMask, j);
                break;
            }
        }
    }

    for(int i=0; i<4; i++) {
        int tmp = maxArr[i] - masks[i] + 1;
        if(tmp < 0) tmp = 0;
        cout << tmp;
        if(i<3) cout << ".";
    }
    cout << "\n";
    for(int i=0; i<4; i++) {
        cout << 256 - masks[i];
        if(i<3) cout << ".";
    }
}