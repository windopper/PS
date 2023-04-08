#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    return a[1] != b[1] ? a[1] < b[1] : a[0] < b[0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, C, M;
    cin >> N >> C >> M;
    vector<vector<int>> arr;
    for(int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        arr.push_back({a, b, c});
    }

    sort(arr.begin(), arr.end(), compare);

    vector<int> has(N+1, 0);
    int ans = 0;
    for(int i=0; i<M; i++) {
        int maxBox = 0;
        for(int j=arr[i][0]; j<arr[i][1]; j++) {
            maxBox = max(maxBox, has[j]);
        }
        int cap = min(arr[i][2], C - maxBox);
        for(int j=arr[i][0]; j<arr[i][1]; j++) {
            has[j] += cap;
        }
        ans += cap;
    }

    cout << ans;
}