#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int>& arr, int l, int r) {
    vector<int> sorted(arr.size());
    if(l < r) {
        int m = (l + r) >> 1;
        solve(arr, l, m);
        solve(arr, m+1, r);
        int s = l; int e = m+1;
        for(int i=l; i<=r; i++) {
            if(s <= m && arr[s] <= arr[e]) {
                sorted[i] = arr[s++];
            }
            else {
                sorted[i] = arr[e++];
            }
        }
        for(int i=l; i<=r; i++) {
            arr[i] = sorted[i];
        }
    }
    return sorted;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i=0; i<N; i++) cin >> arr[i];
    vector<int> sorted = solve(arr, 0, arr.size() - 1);
    for(int cur : sorted) cout << cur << " ";
}