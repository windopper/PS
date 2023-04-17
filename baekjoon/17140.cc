#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int r, c, k;
    cin >> r >> c >> k;
    --r; --c;
    vector<vector<int>> arr(3, vector<int>(3));
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) cin >> arr[i][j];
    }

    int time = 0;
    while(time < 100) {
        if(arr[r][c] == k) {
            cout << time;
            return 0;
        }

        int columns = arr[0].size();
        int rows = arr.size();
        vector<vector<int>> sorted;
        if(rows >= columns) {
            for(int i=0; i<arr.size(); i++) {
                vector<int> count(101, 0);
                vector<int> vis(101, 0);
                for(int j=0; j<arr[i].size(); j++) {
                    count[arr[i][j]]++;
                }

                vector<int> newRow;
                vector<int> sequence;
                for(int j=0; j<arr[i].size(); j++) {
                    if(vis[arr[i][j]]) continue;
                    if(arr[i][j] == 0) continue;
                    vis[arr[i][j]] = 1;
                    newRow.push_back(arr[i][j]);
                    sequence.push_back(arr[i][j]);
                }
            }
        }
        else {

        }
    }
    cout << -1;
}