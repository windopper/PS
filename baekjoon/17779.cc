#include <bits/stdc++.h>

using namespace std;

int maxPop = 0;
int minPop = 987654321;
int N;
vector<vector<int>> arr;

void solve(int x, int y, int d1, int d2) {
    vector<vector<int>> vec(N+2, vector<int>(N+2));
    for(int i=0; i<=d1; i++) {
        vec[y-i].push_back(x+i);
        vec[y+d2-i].push_back(x+d2+i);
    }
    for(int i=0; i<=d2; i++) {
        vec[y+i].push_back(x+i);
        vec[y-d1+i].push_back(x+d1+i);
    }
    int ret = 0;
    for(int i=1; i<=N; i++) {
        if(vec[i].empty()) continue;
        if(vec[i].size() == 1) {
            ret += arr[i][vec[i][0]];
            continue;
        }
        int x1 = vec[i][0];
        int x2 = vec[i][1];
        if(x1 > x2) swap(x1, x2);
        for(int j=x1; j<=x2; j++) {
            ret += arr[i][j];
        }
    }

    maxPop = max(maxPop, ret);
    minPop = min(minPop, ret);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    arr.resize(N+2, vector<int>(N+2));
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            for(int d1=1; d1<=N; ++d1) {
                for(int d2=1; d2<=N; ++d2) {
                    if(j < j + d1 + d2 && j + d1 + d2 <= N &&
                    1 <= i + d1 && i-d1 < i && i < i+d2 && i+d2 <=N) {
                        solve(j, i, d1, d2);
                    }
                }
            }
        }
    }

    cout << maxPop - minPop;
}