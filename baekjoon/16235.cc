#include <bits/stdc++.h>

using namespace std;
int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[8] = {1, -1, 0, 0, -1, 1, 1, -1};
vector<vector<vector<int>>> age; // 나무 나이
vector<vector<int>> feed; // 현재 양분
vector<vector<int>> addi; // 추가되는 양분
int N, M, K;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    feed.assign(N, vector<int>(N));
    addi.resize(N, vector<int>(N));
    age.resize(N, vector<vector<int>>(N, vector<int>()));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            feed[i][j] = 5;
            cin >> addi[i][j];
        }
    }

    for(int i=0; i<M; i++) {
        int x, y, Age;
        cin >> x >> y >> Age;
        x--; y--;
        age[x][y].push_back(Age);
    }

    for(; K>0; --K) {
        //봄
        vector<vector<int>> deadTrees(N, vector<int>(N, 0));
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                vector<int> _age = age[i][j];
                sort(_age.begin(), _age.end());
                vector<int> newAge;
                int curFeed = feed[i][j];
                for(int _a : _age) {
                    if(_a <= curFeed) {
                        curFeed -= _a;
                        newAge.push_back(_a+1);
                    }
                    else {
                        deadTrees[i][j] += _a/2;
                    }
                }
                feed[i][j] = curFeed;
                age[i][j] = newAge;
            }
        }

        // 여름

        // 가을
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                vector<int> _ages = age[i][j];
                for(int _age : _ages) {
                    if((_age % 5) != 0) continue;
                    for(int k=0; k<8; k++) {
                        int nx = j + dx[k];
                        int ny = i + dy[k];
                        if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
                        age[ny][nx].push_back(1);
                    }
                }
            }
        }

        // 겨울
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                feed[i][j] += addi[i][j] + deadTrees[i][j];
            }
        }
    }

    int ans = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            ans += age[i][j].size();
        }
    }

    cout << ans;
}