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
        for(int i=0; i<4; i++) {
            int t = stoi(s.substr(i*4, 3));
            minArr[i] = min(minArr[i], t);
            maxArr[i] = max(maxArr[i], t);
            bits.push_back(t);
        }
        arr.push_back(bits);
    }

    int masks[4] = {0, };
    for(int i=0; i<4; i++) {
        for(int j=1; j<256; j=j<<1) {
            if(maxArr[i] - minArr[i] < j) {
                masks[i] = j;
                break;
            }
        }
    }

    for(int i=0; i<4; i++) {
        cout << maxArr[i] - masks[i];
        if(i<3) cout << ".";
    }
    cout << "\n";
}