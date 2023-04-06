#include <bits/stdc++.h>

using namespace std;
vector<deque<int>> arr(4);

// dir -> 1 시계
// dir -> -1 반시계
void rotate(int cur, int dir, vector<int>& visited) {
    if(visited[cur] == 1) return;
    visited[cur] = 1;
    if(cur + 1 <= 3) {
        // 극이 같을때 회전 방향 같음
        if(arr[cur][2] == arr[cur+1][6]) {
            //rotate(cur+1, dir, visited);
        }
        // 극이 다를 때 회전 방향 다름
        else {
            rotate(cur+1, -dir, visited);
        }
    }
    
    if(cur - 1 >= 0) {
        if(arr[cur][6] == arr[cur-1][2]) {
            //rotate(cur-1, dir, visited);
        }
        else {
            rotate(cur-1, -dir, visited);
        }
    }

    // rotate
    if(dir == 1) {
        int t = arr[cur].back();
        arr[cur].pop_back();
        arr[cur].push_front(t);
    }
    else {
        int t = arr[cur].front();
        arr[cur].pop_front();
        arr[cur].push_back(t);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int K;
    for(int i=0; i<4; i++) {
        string s;
        cin >> s;
        for(int j=0; j<8; j++) {
            arr[i].push_back(s[j] - '0');
        }
    }
    cin >> K;
    for(int i=0; i<K; i++) {
        int a, b;
        cin >> a >> b;
        vector<int> visited(4, 0);
        rotate(a-1, b, visited);

        // for(int i=0; i<4; i++) {
        //     for(int j=0; j<8; j++) {
        //         cout << arr[i][j];
        //     }
        //     cout << "\n";
        // }
    }
    int ans = 0;
    for(int i=0; i<4; i++) {
        if(arr[i][0] == 1) {
            ans += pow(2, i);
        }
    }

    cout << ans;
}