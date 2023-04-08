#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr;
int R;
int solve(int cur, int post) {
    if(cur == R) return 0;
    int ret = 0;
    int cnt = 0;
    for(int next : arr[cur]) {
        if(next == post || next == R) continue;
        ret += solve(next, cur);
        ++cnt;
    }
    if(cnt == 0) return 1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    int parent = -1;
    arr.resize(N);
    for(int i=0; i<N; i++) {
        int t;
        cin >> t;
        if(t == -1) parent = i;
        else {
            arr[t].push_back(i);
            arr[i].push_back(t);
        }
    }

    cin >> R;
    cout << solve(parent, -1);
}