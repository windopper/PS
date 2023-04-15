#include <bits/stdc++.h>

using namespace std;
int N, M;
const long long MOD = 10007;

// 모듈라 곱셈 역원을 계산하는 함수
long long mod_inv(long long a, long long p) {
    long long ans = 1, power = p - 2;
    while (power) {
        if (power & 1) ans = (ans * a) % p;
        a = (a * a) % p;
        power /= 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long int N;
    cin >> N;
    long long int res = 0;
    for(long long int i= N/2; i>-1; i--){
        long long int k = N-2*i;
        long long int a = 1;
        long long int b = 1;

        for(long long j=k; j>0; --j) {
            a *= (i+j);
            a %= MOD;
            b *= j;
            b %= MOD;
        }
		
        // 모듈라 곱셈 역원을 적용해서 계산
        long long int inv_b = mod_inv(b, MOD);
        res += (a * inv_b) % MOD;
        res %= MOD;
    }
    cout << res;
}
