/**
 * baekjoon 3197 백조의 호수
*/
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int R, C;
vector<vector<char>> arr;
pair<int, int> swanPosition;

queue<pair<int, int>> waterQueue;
queue<pair<int, int>> waterNextQueue;
bool visited[1501][1501] = {0, };
queue<pair<int, int>> swanQueue;
queue<pair<int, int>> swanNextQueue;

void bfsMelt() {

    while (!waterQueue.empty()) {

        pair<int, int> nxt = waterQueue.front();
        waterQueue.pop();

        for(int i=0; i<4; i++) {
            int nx = nxt.first + dx[i];
            int ny = nxt.second + dy[i];
            if (nx >= 0 && nx < C && ny >= 0 && ny < R) {
                if (arr[ny][nx] == 'X') {
                    arr[ny][nx] = '.';
                    waterNextQueue.push(make_pair(nx, ny));
                }
            }
        }
    }
}

bool bfsSwan() {

    while(!swanQueue.empty()) {
        pair<int, int> st = swanQueue.front();
        swanQueue.pop();
        int x = st.first;
        int y = st.second;
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < C && ny >= 0 && ny < R && visited[ny][nx] == 0) {
                visited[ny][nx] = 1;
                if (arr[ny][nx] == '.') {
                    swanQueue.push(make_pair(nx, ny));
                }
                else if(arr[ny][nx] == 'X') {
                    swanNextQueue.push(make_pair(nx, ny));
                }
                else {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C;

    for(int i=0; i<R; i++) {
        vector<char> vec;
        for(int j=0; j<C; j++) {
            char c;
            cin >> c;
            vec.push_back(c);
            if ( c == 'L' ) {
                swanPosition = make_pair(j, i);
            }
            // 백조 위치 저장
            if ( c != 'X' ) {
                waterQueue.push({j, i});
            }
            // 물 위치 저장
        }
        arr.push_back(vec);
    }

    int step = 0;
    swanQueue.push(swanPosition);
    visited[swanPosition.second][swanPosition.first] = true;
    while (true)
    {
        bool find = bfsSwan();
        if (find) {
            cout << step;
            break;
        }
        bfsMelt();
        waterQueue = waterNextQueue;
        swanQueue = swanNextQueue;
        while(!waterNextQueue.empty()) waterNextQueue.pop();
        while(!swanNextQueue.empty()) swanNextQueue.pop();
        step++;
    }
;
}