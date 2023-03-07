#include <bits/stdc++.h>

using namespace std;
int N;
pair<int, int> moves[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<int>> sandStorm = {{0, 0, 2, 0, 0}, {0, 10, 7, 1, 0}, {5, 100, 0, 0, 0}, {0, 10, 7, 1, 0}, {0, 0, 2, 0, 0}};
vector<vector<int>> arr;

vector<vector<int>> getRotateSandStorm(vector<vector<int>>& v) {
    vector<vector<int>> temp(5, vector<int>(5));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            temp[5 - j - 1][i] = v[i][j];
        }
    }
    return temp;
}

int solve(int x, int y, int rotate, int dash, int moveCnt, int sands) {
    if (x == 0 && y == 0) return sands;

    int nx = x + moves[rotate].first;
    int ny = y + moves[rotate].second;

    // 모래 날리기
    int inside = 0, outside = 0;
    int a, b;
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (sandStorm[i + 2][j + 2] == 100) {
                a = nx + j;
                b = ny + i;
                continue;
            }
            if (nx + j < 0 || nx + j >= N || ny + i < 0 || ny + i >= N) {
                outside += arr[ny][nx] * sandStorm[i + 2][j + 2] / 100;
                continue;
            }
            int c = arr[ny][nx] * sandStorm[i + 2][j + 2] / 100;
            inside += c;
            arr[ny + i][nx + j] = c;
        }
    }

    if (a >= 0 && a < N && b >= 0 && b < N) {
        arr[b][a] = arr[ny][nx] - inside;
    } else {
        sands += arr[ny][nx] - inside;
    }
    arr[ny][nx] = 0;

    cout << sands << " ";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // 모래바람 회전
    sandStorm = getRotateSandStorm(sandStorm);

    if (moveCnt <= 0) {
        rotate = rotate == 3 ? 0 : rotate + 1;
        if (rotate == 0 || rotate == 2) dash++;
        moveCnt = dash;
    }

    return solve(nx, ny, rotate, dash, moveCnt - 1, sands);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    arr.assign(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> arr[i][j];
    }

    cout << solve(N / 2, N / 2, 0, 1, 0, 0);
}