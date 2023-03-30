#include <bits/stdc++.h>

using namespace std;
int N;
vector<vector<int>> balls;
int weightSum[200001] = {0, };
int colorSum[200001] = {0, };

bool compare(vector<int> &a, vector<int> &b) {
    return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        int u, v;
        cin >> u >> v;
        balls.push_back({v, u, i});
    }

    sort(balls.begin(), balls.end());

    int ret = 0;
    int ans[200001] = {0, };

    for(int i=0; i<N; i++) {
        int v = balls[i][0];
        int c = balls[i][1];
        int origin = balls[i][2];

        weightSum[v] += v;
        colorSum[c] += v;
        ret += v;
        ans[origin] = ret - colorSum[c] - weightSum[v] + v;
        if(i != 0 && balls[i-1][1] == c && balls[i-1][0] == v) {
            ans[origin] = ans[balls[i-1][2]];
        }
    }

    for(int i=0; i<N; i++) cout << ans[i] << '\n';

}