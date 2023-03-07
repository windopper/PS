#include <bits/stdc++.h>

using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<vector<char>> arr;
pair<int, int> blue;
pair<int, int> red;

int bfs() {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    queue<int> cnt;
    q.push({blue, red});
    cnt.push(0);
    while (!q.empty()) {
        int bx = q.front().first.first;
        int by = q.front().first.second;
        int rx = q.front().second.first;
        int ry = q.front().second.second;

        // 상하좌우로 굴리기
        for (int i = 0; i < 4; i++) {
            bool isBlueInHole = false;
            bool isRedInHole = false;
            bool isBlueMeetRed = false;
            bool isRedMeetBlue = false;

            int nx = dx[i];
            int ny = dy[i];
            int blueMul = 1;
            int redMul = 1;

            // 파란구슬 굴리기
            while (true) {
                // 구멍에 들어갔으면
                int nextX = bx + nx * blueMul;
                int nextY = by + ny * blueMul;
                if (arr[nextY][nextX] == 'O') {
                    isBlueInHole = true;
                    break;
                }
                // 중간에 빨간 구슬 만나면 벽 2칸뒤에 붙이기
                if (nextY == ry && nextX == rx) {
                    isBlueMeetRed = true;
                }
                if (arr[nextY][nextX] == '#') {
                    // 처음에 벽에 박았을 떄
                    // 벽에 맞닥뜨렸을 때 오면서 빨간 구슬을 만났으면 한칸 더 뒤로
                    if (isBlueMeetRed) --blueMul;
                    --blueMul;
                    break;
                }
                ++blueMul;
            }

            // 빨간구슬 굴리기
            while (true) {
                // 구멍에 들어갔으면
                int nextX = rx + nx * redMul;
                int nextY = ry + ny * redMul;
                if (arr[nextY][nextX] == 'O') {
                    isRedInHole = true;
                    break;
                }
                // 중간에 파란 구슬 만나면 벽 2칸 뒤에 붙이기
                if (nextY == by && nextX == bx) {
                    isRedMeetBlue = true;
                }
                if (arr[nextY][nextX] == '#') {
                    // 처음에 벽에 박았을 떄
                    // 벽에 맞닥뜨렸을 때 오면서 파란 구슬을 만났으면 한칸 더 뒤로
                    if (isRedMeetBlue) --redMul;
                    --redMul;
                    break;
                }
                ++redMul;
            }

            // 빨간구슬만 구멍에 들어갔으면 탈출
            if (!isBlueInHole && isRedInHole) {
                return cnt.front() + 1;
            }

            // 둘다 움직이지 않는다면 실패
            if (redMul == 0 && blueMul == 0) continue;
            // 파란구슬이 탈출했다면 실패
            if (isBlueInHole) continue;

            q.push({make_pair(bx + nx * blueMul, by + ny * blueMul), make_pair(rx + nx * redMul, ry + ny * redMul)});
            cnt.push(cnt.front() + 1);
        }

        if (cnt.front() == 10) {
            return -1;
        }

        cnt.pop();
        q.pop();
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    arr.assign(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            switch (arr[i][j]) {
                case 'B':
                    blue = make_pair(j, i);
                    arr[i][j] = '.';
                    break;
                case 'R':
                    red = make_pair(j, i);
                    arr[i][j] = '.';
                    break;
            }
        }
    }

    cout << bfs();
}