#include <bits/stdc++.h>
#include <ios>

using namespace std;
vector<int> arr;
int N, S;
int solve(int sum, int idx) {
    if(idx == N) {
        if(sum == S) return 1;
        else return 0;
    }
    int res = 0;
    res += solve(sum+arr[idx], idx+1);
    res += solve(sum, idx+1);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> S;
    arr.resize(N);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<int> path;
    int ans = solve(0, 0);
    if(S == 0) --ans;
    cout << ans;
}