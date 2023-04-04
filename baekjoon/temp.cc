#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N; 
    cin >> N;
    int i = 666;
    int cnt = 0;
    while(1) {
        string t = to_string(i);
        for(int j=0; j<t.length()-2; j++) {
            if(t[j] == '6' && t[j+1] == '6' && t[j+2] == '6') {
                ++cnt;
                if(cnt == N) {
                    cout << i;
                    return 0;
                }
                break;
            }
        }
        i++;
    }
}