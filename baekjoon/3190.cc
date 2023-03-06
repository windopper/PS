#include <bits/stdc++.h>

using namespace std;
int N, K, L;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int curDir = 0;
// R, D, L, U
vector<pair<int, char>> cmd;

void changeDirection(char c) {
    if(c == 'L') {
        curDir = curDir == 0 ? 3 : curDir - 1;
    }
    else {
        curDir = curDir == 3 ? 0 : curDir + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    int apples[N][N];
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) apples[i][j] = 0;
    for(int i=0; i<K; i++) {
        int a, b;
        cin >> a >> b;
        apples[a-1][b-1] = 1;
    }
    cin >> L;
    for(int i=0; i<L; i++) {
        int x;
        char c;
        cin >> x >> c;
        cmd.push_back({x, c});
    }

    sort(cmd.begin(), cmd.end(), greater<>());

    queue<pair<int, int>> q;
    q.push({0, 0});
    int time = 0;
    while(true){


        bool hasApple = false;
        // 이동
        int nx = dx[curDir];
        int ny = dy[curDir];
        int headX = q.back().first;
        int headY = q.back().second;
        q.push({headX + nx, headY + ny});
        
        if(headX + nx <0 || headX + nx>=N || headY+ny<0 || headY+ny>=N) {
            cout << time + 1;
            return 0;
        } 

        queue<pair<int, int>> temp = q;
        while (temp.size() > 1) {
            int tx = temp.front().first;
            int ty = temp.front().second;
            temp.pop();
            if(tx == headX + nx && ty == headY + ny) {
                cout << time + 1;
                return 0;
            }
        }

        if(apples[headY+ny][headX+nx]) {
            hasApple = true;
            apples[headY+ny][headX+nx] = 0;
        }

        // 사과를 안 먹었다면 꼬리 지우기
        if(!hasApple) {
            q.pop();
        }

        ++time;

        int ct = cmd.back().first;
        char c = cmd.back().second;
        if(ct == time) {
            changeDirection(c);
            cmd.pop_back();
        }
    }
}