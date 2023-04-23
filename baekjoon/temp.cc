#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    sort(arr.begin(), arr.end());
    int l = 0;
    int r = n-1;
    int ans = 0;
    while(l < r) {
        if(l >= r) break;
        int res = arr[l] + arr[r];
        if(res > x) {
            --r;
        }
        else if(res < x) {
            ++l;
        }
        else {
            ++ans;
            --r;
            ++l;
        }
    }
    cout << ans;
}