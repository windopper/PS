#include <bits/stdc++.h>

using namespace std;
int arr[100001];
int diff[100001];

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<N-1; i++) {
        diff[i] = arr[i+1] - arr[i];
    }

    int t = diff[0];
    for(int i=1; i<N-1; i++) {
        if(t < diff[i]) {
            t = gcd(diff[i], t);
        }
        else t = gcd(t, diff[i]);
    }

    int ans = 0;

    for(int i=0; i<N-1; i++) {
        ans += (diff[i] / t) - 1;
    }

    cout << ans;
}