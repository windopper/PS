#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0): cin.tie(0); cout.tie(0);
    int num[20];
    char op[20];
    int N;
    cin >> N;
    string s;
    cin >> s;
    for(int i=0; i<N; i++) {
        if(i%2==0) {
            num[i/2] = atoi(&s[i]);
        }
        else {
            op[i/2] = s[i];
        }
    }
}