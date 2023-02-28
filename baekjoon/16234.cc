#include <bits/stdc++.h>

using namespace std;

struct pos {
    int x, y;
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int N, L, R;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> L >> R;
    int p[N][N];
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> p[i][j];
        }
    }

    bool visited[N][N] = {false, };
    int days = 0;

    while(true) {

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                visited[i][j] = false;
            }
        }

        // 인구 이동이 있었는가?
        bool checkMove = false;

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(visited[i][j]) continue;
                queue<pos> q;
                vector<pos> unions;
                int totalPopulation = p[i][j];

                q.push({j, i});
                visited[i][j] = true;
                unions.push_back({j, i});

                while(!q.empty()) {
                    int x = q.front().x;
                    int y = q.front().y;
                    int base = p[y][x];
                    q.pop();

                    for(int k=0; k<4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx>=0 && nx<N && ny>=0 && ny<N && !visited[ny][nx]) {
                            int diff = abs(base - p[ny][nx]);
                            if(diff >= L && diff <= R) {
                                checkMove = true;
                                visited[ny][nx] = true;
                                unions.push_back({nx, ny});
                                totalPopulation += p[ny][nx];
                                q.push({nx, ny});
                            }
                        }
                    }
                }

                int div = totalPopulation / unions.size();

                for(pos &u : unions) {
                    p[u.y][u.x] = div;
                }
            }
        }

        if(!checkMove) {
            cout << days;
            return 0;
        }

        days++;
    }
}