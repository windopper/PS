#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> miarr(N);
    vector<int> mxarr(N);
    for(int i=0; i<N; i++) {
        int t; cin >> t;
        if(t < 0) miarr.push_back(t);
        else mxarr.push_back(t);
    }
    sort(miarr.begin(), miarr.end(), greater<>());
    sort(mxarr.begin(), mxarr.end());
    int ans = 0;
    int l = miarr.size() - 1;
    int r = 0;
    while(1) {
        int cnt = 0;
        if(abs(miarr.back()) < mxarr.back()) {
            while(l < miarr.size() && cnt <= M) {
                --l;
                ++cnt;
            }
            if(l < miarr.size()) {
                ans += -miarr[l-1] * 2;
            }
            else {
                ans += -miarr[l-1];
            }
        }
        else {
            while(r < mxarr.size() && cnt <= M) {
                ++r;
                ++cnt;
            }
            if(r < mxarr.size()) {
                ans += mxarr[r-1] * 2;
            }
        }

        if(l < miarr.size() || r < mxarr.size()) {
            ans += 
        }
    }

    cout << ans;
}