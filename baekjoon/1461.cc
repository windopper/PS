#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> loc;
    vector<int> mloc;
    for(int i=0; i<N; i++) {
        int t; cin >> t;
        if(t<0) {
            mloc.push_back(-t);
        }
        else loc.push_back(t);
    }
    sort(mloc.begin(), mloc.end());
    sort(loc.begin(), loc.end());
    int ans = 0;
    int temp = N;
    while(1) {
        if(mloc.empty() && loc.empty()) break;
        int cnt = 0;
        while(cnt < M) {
            if(loc.empty()) break;
            if(cnt == 0) {
                if(temp <= M) ans += loc.back();
                else ans += loc.back() * 2;
            }
            loc.pop_back();
            --temp;
            ++cnt;
        }
        cnt = 0;
        while(cnt < M) {
            if(mloc.empty()) break;
            if(cnt == 0) {
                if(temp <= M) ans += mloc.back();
                else ans += mloc.back() * 2;
            }
            mloc.pop_back();
            --temp;
            ++cnt;
        }
    }

    cout << ans;
}