#include <bits/stdc++.h>

using namespace std;

int arr[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[0][i];
    }

    int ans = 0;
    while (true) {
        int minValue = 10000;
        int maxValue = 1;
        for (int i = 0; i < N; i++) {
            minValue = min(minValue, arr[0][i]);
            maxValue = max(maxValue, arr[0][i]);
        }

        if (maxValue - minValue <= K) {
            cout << ans;
            break;
        }

        // 가장 적은 어항에 물고기 넣기
        for (int i = 0; i < N; i++) {
            if (arr[0][i] == minValue) ++arr[0][i];
        }

        int L = 0, H = 1, W = 1;
        // 왼쪽 포인터, 높이, 너비
        // H = 인덱스 % 2 == 1 마다 1 증가
        // L = 이전 L + 이전 W
        // W = 인덱스 % 2 == 0 마다 1 증가 (인덱스가 0일때 증가 하지 않음)
        // 기저 조건 -> N - L - W < H 일때 종료
        int idx = 0;
        while (N - L - W >= H) {
            // 어항 쌓기
            for (int i = L + W - 1; i >= L; i--) {
                for (int j = 0; j < H + 1; j++) {
                    arr[L + W - i][L + W + j] = arr[j][i];
                    arr[j][i] = 0;
                }
            }
            idx++;
            L += W;
            if (idx % 2 == 1)
                ++H;
            else {
                if (idx != 0) ++W;
            }
        }

        // 어항에 있는 물고기의 수 조절하기
        int newArr[100][100];
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (arr[i][j] == 0) continue;

                int newValue = arr[i][j];
                for (int k = 0; k < 4; k++) {
                    // 인접한 배열에 대해 계산하기
                    int nx = j + dx[k];
                    int ny = i + dy[k];
                    if (arr[ny][nx] == 0) continue;

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    int d = abs(arr[ny][nx] - arr[i][j]) / 5;
                    if (arr[ny][nx] > arr[i][j]) {
                        newValue += d;
                    } else if (arr[ny][nx] < arr[i][j]) {
                        newValue -= d;
                    }
                }
                newArr[i][j] = newValue;
            }
        }

        // 복제하기
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) arr[i][j] = newArr[i][j];
        }

        // 어항 다시 바닥에 놓기
        for (int i = L; i < L + W; i++) {
            for (int j = 0; j < H; j++) {
                arr[0][H * (i - L) + j] = arr[j][i];
                arr[j][i] = 0;
            }
        }

        // 첫번째 공중 부양 작업 하기
        for (int i = N / 2 - 1; i >= 0; --i) {
            arr[1][N - i - 1] = arr[0][i];
            arr[0][i] = 0;
        }

        // 두번째 공중 부양 작업 하기
        for (int i = N / 2 + N / 4 - 1; i >= N / 2; --i) {
            arr[2][N + N / 2 - i - 1] = arr[1][i];
            arr[3][N + N / 2 - i - 1] = arr[0][i];
            arr[1][i] = 0;
            arr[0][i] = 0;
        }

        // 물고기 수 조절하기
        int secondNewArr[100][100];
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if (arr[i][j] == 0) continue;

                int newValue = arr[i][j];
                for (int k = 0; k < 4; k++) {
                    // 인접한 배열에 대해 계산하기
                    int nx = j + dx[k];
                    int ny = i + dy[k];
                    if (arr[ny][nx] == 0) continue;

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    int d = abs(arr[ny][nx] - arr[i][j]) / 5;
                    if (arr[ny][nx] > arr[i][j]) {
                        newValue += d;
                    } else if (arr[ny][nx] < arr[i][j]) {
                        newValue -= d;
                    }
                }
                secondNewArr[i][j] = newValue;
            }
        }

        // 복제하기
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) arr[i][j] = secondNewArr[i][j];
        }

        // 바닥에 일렬로 놓는 작업 하기
        for (int i = N / 2 + N / 4; i < N; i++) {
            for (int j = 0; j < 4; j++) {
                arr[0][(i - N / 2 - N / 4) * 4 + j] = arr[j][i];
                arr[j][i] = 0;
            }
        }

        ++ans;
    }
}