#include <bits/stdc++.h>
#include <limits>

using namespace std;
int arr[100001];
int K, N;

int check(int m) {
    long long ret = 0;
    for(int i=0; i<K; i++) ret += (arr[i] / m);
    // 더 많음
    if(ret >= N) return 1;
    // 더 적음
    else return -1;
}

long long solve(long long s, long long e) {
    long long ans = 0;
    while(s <= e) {
        long long m = (s+e) / 2;
        int result = check(m);
        if(result == 1) {
            ans = max(ans, m);
            s = m + 1;
        }
        else if(result == -1) {
            e = m-1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> K >> N;
    for(int i=0; i<K; i++) {
        cin >> arr[i];
    }
    long long maxElement = *max_element(arr, arr+K);
    cout << solve(1, maxElement);
}