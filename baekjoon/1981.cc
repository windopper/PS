#include <bits/stdc++.h>

using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int arr[101][101];
int n;
int minElement = numeric_limits<int>::max();
int maxElement = 0;

bool pass(int m) {
    for(int k=minElement; k<=maxElement; k++) {
        vector<vector<int>> visited(n, vector<int>(n, 1));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(arr[i][j] >= k && arr[i][j] - k <= m) visited[i][j] = 0;
            }
        }
        queue<vector<int>> q;
        if (!visited[0][0]) {
            q.push({0, 0});
        }
        while (!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            if (cur[0] == n - 1 && cur[1] == n - 1) return true;
            for (int i = 0; i < 4; i++) {
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if (visited[ny][nx]) continue; 
                visited[ny][nx] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            minElement = min(minElement, arr[i][j]);
            maxElement = max(maxElement, arr[i][j]);
        }
    }

    int s = 0;
    int e = maxElement - minElement;
    int ans = maxElement - minElement;

    while (s <= e) {
        int m = (s+e)/2;
        bool status = pass(m);
        // 통과하면 더 줄여도 되겠다
        if (status) {
            ans = m;
            e = m-1;
        } else {
            // ans = m;
            s = m+1;
        }
    }
    cout << ans;
}