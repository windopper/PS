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
map<pair<int, int>, int> qorwh;
pair<int, int> parent[1501][1501];
int idx = 0;

void melt(int x, int y, vector<vector<int>>& visited) {
    // 빙판을 녹여볼까
    if (arr[y][x] == 'X' || visited[y][x] == 1) return;

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < C && ny >= 0 && ny < R 
            && visited[ny][nx] == 0 ) {
            visited[ny][nx] = 1;
            if ( arr[ny][nx] == '.' ) melt(nx, ny, visited);
            else if ( arr[ny][nx] == 'X' ) {
                arr[ny][nx] = '.';
            };
        }
    }
}

void meltStep() {
    vector<vector<int>> visited(R, vector<int>(C, 0));
    // 초기화
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            melt(j, i, visited);
        }
    }

}

void bfs(int x, int y, pair<int, int> p, vector<vector<int>>& visited,
    queue<pair<int, int>> S) {
    if(arr[y][x] == 'X' || visited[y][x] == 1) return;
    queue<pair<int, int>> useLater;
    S.push({x, y});
    visited[y][x] = 1;
    while(!S.empty()) {
        pair<int, int> st = S.front();
        S.pop();
        x = st.first;
        y = st.second;
        parent[y][x] = p;
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < C && ny >= 0 && ny < R && visited[ny][nx] == 0) {
                visited[ny][nx] = 1;
                if (arr[ny][nx] == '.' || arr[ny][nx] == 'L') {
                    S.push({nx, ny});
                }
                else {
                    arr[ny][nx] = '.';
                    // bfs 한번에 얼음 녹이기와 백조찾기를 동시에 가능할까?
                    //useLater.push_back({nx, ny});
                }
            }
        }
    }
}

bool checkCanMeet(int x, int y) {
    pair<int, int> temp = parent[y][x];
    pair<int, int> p = {x, y};
    return temp != p;
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
                qorwh[{j, i}] = ++idx;
            }
            // 백조 위치 저장
        }
        arr.push_back(vec);
    }

    int step = 0;

    map<pair<int, int>, int>::iterator it = qorwh.begin();
    int x = it->first.first;
    int y = it->first.second;
    it++;
    int x2 = it->first.first;
    int y2 = it->first.second;
    parent[y2][x2] = it->first;
    // 두번째 백조는 자기 자신을 부모로
    while (true)
    {
        queue<pair<int, int>> useLater;    
        vector<vector<int>> visited(R, vector<int>(C, 0));
        bfs(x, y, {x, y}, visited, useLater);
        // 첫번째 백조에 대해 이동가능한 모든 물에 대해
        // 부모를 자신으로 설정
        // 만약 두번째 백조가 있다면 그 또한 부모를 자신으로 설정
        cout << endl;
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                bfs(j, i, {x, y}, visited, useLater);
                cout << arr[i][j];
            }
            cout << endl;
        }

        if (checkCanMeet(x2, y2)) {
            cout << step;
            break;
        }
        //meltStep();
        // 다음 녹이기

        step++;
    }

;
}