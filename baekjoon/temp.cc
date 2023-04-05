#include <bits/stdc++.h>

using namespace std;
int N, M;
int arr[8];

int solve(vector<int>& picked, int cnt, int r) {
    if(cnt > r) return 0;
    if(cnt == r) {
        for(int i=0; i<picked.size(); i++) {
            if(picked[i] == 1) cout << arr[i] << " ";
        }
        cout << "\n";
        return 0;
    }

    for(int i=0; i<N; i++) {
        picked[i] = 1;
        solve(picked, cnt + 1, r);
        picked[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+N);
    vector<int> picked(N, 0);
    solve(picked, 0, M);
}