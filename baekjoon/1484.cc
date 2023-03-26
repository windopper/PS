#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int G;
    cin >> G;
    long long left = 1;
    long long right = 1;
    int cnt = 0;
    while(1) {
        if(right - left == 1 && pow(right, 2) - pow(left, 2) > G) break;
        long long diff = pow(right, 2) - pow(left, 2);
        if(diff < G) ++right;
        else if(diff > G) ++left;
        else {
            ++cnt;
            cout << right << "\n";
            ++right;
        }
    }
    if(cnt == 0) cout << -1;
}