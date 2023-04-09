#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> arr(16, vector<int>(16, 0));
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N = 16;

bool isOutOfRange(int x, int y) { return x < 0 || x >= N || y < 0 || y >= N; }
bool hasDust(int x, int y) { return arr[y][x] == 1; }

string getCommand() {
    int m = 15;
    string ret = "";
    string c1 = "RFR";
    string c2 = "DF";
    string c3 = "LFL";
    ret += 'd';
    for(int i=0; i<15; i++) {
        for(int j=0; j<15; j++) {
            if(i % 2 == 0) ret += c1;
            else ret += c3;
        }
        ret += 'd';
    }

    string c4 = "UFU";
    for (int i = 0; i < 14; i++) {
        ret += c4;
    }
    for (int i = 0; i < 15; i++) {
        ret += c3;
    }

    string c5 = "DFD";
    for(int i=0; i<15; i++) {
        ret += c5;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = getCommand();
    cout << s << '\n';
    cout << "length : " << s.size() << "\n";
    srand(time(nullptr));

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            long double rv = ((long double)rand()) / (long double)RAND_MAX;
            if( rv> 0.5) {
                arr[i][j] = 1;
            }
        }
    }

    int x = 0, y = 0;
    for (char c : s) {
        switch (c) {
            case 'F': {
                if (hasDust(x, y)) {
                    arr[y][x] = 0;
                }
                else {
                    arr[y][x] = 1;
                }
                continue;
            }
            case 'u':
            case 'U': {
                int nx = x + dx[0];
                int ny = y + dy[0];
                if (isOutOfRange(nx, ny)) continue;
                if (c == 'U' && !hasDust(x, y)) {
                    x = nx;
                    y = ny;
                } else if (c == 'u') {
                    x = nx;
                    y = ny;
                }
                continue;
            }
            case 'd':
            case 'D': {
                int nx = x + dx[1];
                int ny = y + dy[1];
                if (isOutOfRange(nx, ny)) continue;
                if (c == 'D' && !hasDust(x, y)) {
                    x = nx;
                    y = ny;
                } else if (c = 'd') {
                    x = nx;
                    y = ny;
                }
                continue;
            }
            case 'l':
            case 'L': {
                int nx = x + dx[2];
                int ny = y + dy[2];
                if (isOutOfRange(nx, ny)) continue;
                if (c == 'L' && !hasDust(x, y)) {
                    x = nx;
                    y = ny;
                } else if (c == 'l') {
                    x = nx;
                    y = ny;
                }
                continue;
            }
            case 'r':
            case 'R': {
                int nx = x + dx[3];
                int ny = y + dy[3];
                if (isOutOfRange(nx, ny)) {
                    continue;
                }
                if (c == 'R' && !hasDust(x, y)) {
                    x = nx;
                    y = ny;
                } else if (c == 'r') {
                    x = nx;
                    y = ny;
                }
                continue;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    cout << "finish loc: " << x << " " << y;
}