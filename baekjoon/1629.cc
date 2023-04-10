#include <bits/stdc++.h>

using namespace std;
long long A, B, C;

long long solve(long long a, long long b) {
    if(b == 0) return 1;
    if(b == 1) return a % C;
    if(b == 2) return a * a % C;
    if(b % 2 == 1) {
        return a * solve(a, b-1) % C;
    }
    return solve(a, b / 2) * solve(a, b / 2) % C;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> A >> B >> C;
    cout << solve(A, B);
}