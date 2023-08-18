#include <bits/stdc++.h>

using namespace std;
vector<long long> vec;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        long long a;
        cin >> a;
        vec.push_back(a);
    }

    sort(vec.begin(), vec.end());

    long long ans = 0;

    if (N % 2 == 0) {
        for(int i=0; i< N/2; i++) {
            ans = max(ans, vec[i] + vec[N - 1 - i]);
        }
    }
    else {
        for(int i=0; i< N/2; i++) {
            ans = max(ans, vec[i] + vec[N - 2 - i]);
        }
        ans = max(ans, vec[N-1]);
    }

    cout << ans;
}