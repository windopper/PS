#include <bits/stdc++.h>

using namespace std;
int N, M, x, y, K;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int arr[20][20];
int diceh[4] = {0, 0, 0, 0};
int dicew[4] = {0, 0, 0, 0};

bool moveDice(int cmd) {
    int nx = x + dx[cmd - 1];
    int ny = y + dy[cmd - 1];
    if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
        return false;
    }
    int tmp;
    switch (cmd) {
        case 1:
            tmp = dicew[3];
            for (int i = 2; i >= 0; --i) {
                dicew[i + 1] = dicew[i];
            }
            dicew[0] = tmp;
            diceh[1] = dicew[1];
            diceh[3] = dicew[3];
            break;
        case 2:
            tmp = dicew[0];
            for (int i = 1; i < 4; i++) {
                dicew[i - 1] = dicew[i];
            }
            dicew[3] = tmp;
            diceh[1] = dicew[1];
            diceh[3] = dicew[3];
            break;
        case 3:
            tmp = diceh[0];
            for (int i = 1; i < 4; i++) {
                diceh[i - 1] = diceh[i];
            }
            diceh[3] = tmp;
            dicew[1] = diceh[1];
            dicew[3] = diceh[3];
            break;
        case 4:
            tmp = diceh[3];
            for (int i = 2; i >= 0; --i) {
                diceh[i + 1] = diceh[i];
            }
            diceh[0] = tmp;
            dicew[1] = diceh[1];
            dicew[3] = diceh[3];
            break;
    }
    x = nx;
    y = ny;
    return true;
}

void solve(int cmd) {
    if (moveDice(cmd)) {
        if (arr[y][x] > 0) {
            diceh[3] = dicew[3] = arr[y][x];
            arr[y][x] = 0;
        } else {
            arr[y][x] = diceh[3];
        }
        cout << diceh[1] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> y >> x >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int tmp = 0;
        cin >> tmp;
        solve(tmp);
    }
}