#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long N, K;
    cin >> N >> K;
    long long s = 1;
    long long e = N*N;
    long long ans = 0;

    while(s<=e) {
        long long mid = (s+e)/2;
        long long cnt = 0;

        for(int i=1; i<=N; i++) {
            if(i * N < mid) {
                cnt += N;
            }
            else if(i * N >= mid) {
                cnt += (mid / i);
            }
        }
        
        if(cnt < K) {
            s = mid+1;
        }
        else if(cnt >= K) {
            e = mid-1;
        }
    }

    cout << s;
}