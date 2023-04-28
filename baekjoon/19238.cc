#include <bits/stdc++.h>

using namespace std;
int N, M, O;
vector<vector<int>> arr;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

bool comp(pair<int, int>& a, pair<int, int>& b) {
    return a.second != b.second ? a.second < b.second : a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> O;
    arr.resize(N, vector<int>(N));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) cin >> arr[i][j];
    }

    pair<int, int> start;
    pair<int, int> end;
    int a, b;
    cin >> b >> a;
    b--;
    a--;
    start = {a, b};

    vector<vector<int>> starts(N, vector<int>(N, 0));
    vector<vector<pair<int, int>>> ends(N, vector<pair<int ,int>>(N));
    vector<pair<int, int>> startss;
    for(int i=1; i<=M; i++) {
        int sy, sx, ey, ex;
        cin >> sy >> sx >> ey >> ex;
        sy--; sx--; ey--; ex--;
        starts[sy][sx] = i;
        startss.push_back({sx, sy});
        ends[sy][sx] = {ex, ey};
    }

    //sort(startss.begin(), startss.end(), comp);

    bool isFindPerson = true;
    int cnt = 0;
    bool isDone = false;
    int curMinDist = -1;
    pair<int, int> curMinCoord;
    while(O > 0) {
        vector<vector<int>> dis(N, vector<int>(N, 987654321));
        queue<vector<int>> q;
        q.push({start.first, start.second, 0});
        dis[start.second][start.first] = 0;
        //cout << start.first << " " << start.second << '\n';
        while(!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            int x = cur[0];
            int y = cur[1];
            int c = cur[2];

            if(curMinDist == -1 && O < c) {
                cout << -1;
                return 0;
            }

            if(isFindPerson && curMinDist != -1 && curMinDist < c) {
                break;
            }

            if(isFindPerson && starts[y][x]) {
                if(curMinDist == -1) {
                    curMinDist = c;
                    curMinCoord = {x, y};
                }
                else if(curMinDist == c) {
                    pair<int, int> p = make_pair(x, y);
                    if(comp(p, curMinCoord)) {
                        curMinCoord = p;
                    }
                }
            }
            else if(!isFindPerson && end.first == x && end.second == y) {
                O = O - c + c * 2;
                start = {x, y};
                ++cnt;
                isDone = true;
                isFindPerson = true;
                break;
            }

            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0||nx>=N||ny<0||ny>=N) continue;
                if(arr[ny][nx]) continue;
                if(dis[ny][nx] <= c+1) continue;
                dis[ny][nx] = c+1;
                q.push({nx, ny, c+1});
            }
        }

        if(cnt == M) {
            cout << O;
            return 0;
        }

        if(isFindPerson && curMinDist != -1) {
            starts[curMinCoord.second][curMinCoord.first] = 0;
            end = ends[curMinCoord.second][curMinCoord.first];
            start = curMinCoord;
            O -= curMinDist;
            isFindPerson = false;
            isDone = true;
        }

        if(!isDone) {
            break;
        }

        isDone = false;
        curMinDist = -1;
        curMinCoord = {};
    }

    cout << -1;
}