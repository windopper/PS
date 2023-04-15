#include<bits/stdc++.h>

using namespace std;
int N, M;
const long long MOD = 10007;

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
            b *= j;
        }

        res += a/b;
		res %= MOD;
	}
	cout << res;
}
