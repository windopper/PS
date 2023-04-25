#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K;
    cin >> N >> K;
    bool isPrime[1001];
    for(int i=2; i<=N; i++) {
        isPrime[i] = true;
    }
    for(int i=2; i<=N; i++) {
        if(!isPrime[i]) continue;
        for(int j=i; j<=N; j+=i) {
            if(!isPrime[j]) continue;
            isPrime[j] = false;
            --K;
            if(K == 0) {
                cout << j;
                return 0;
            }
        }
    }
}