#include <bits/stdc++.h>

using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<vector<int>> like;
vector<pair<int, int>> locs;
vector<vector<int>> arr;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    arr.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N * N; i++) {
        vector<int> tmp;
        for (int i = 0; i < 5; i++) {
            int f;
            cin >> f;
            tmp.push_back(f);
        }
        like.push_back(tmp);
    }
    for (vector<int> vec : like) {
        pair<int, int> loc;
        int maxEmptyCnt = -1;
        int maxLikeCnt = -1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j]) continue;
                int emptyCnt = 0;
                int likeCnt = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = j + dx[k];
                    int ny = i + dy[k];
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (arr[ny][nx] == 0) {
                        ++emptyCnt;
                        continue;
                    }
                    for (int l = 1; l < 5; l++) {
                        if (arr[ny][nx] == vec[l]) {
                            ++likeCnt;
                            break;
                        }
                    }
                }
                if (maxLikeCnt < likeCnt) {
                    maxLikeCnt = likeCnt;
                    maxEmptyCnt = emptyCnt;
                    loc = {j, i};
                }
                else if(maxLikeCnt == likeCnt) {
                    if(maxEmptyCnt < emptyCnt) {
                        maxLikeCnt = likeCnt;
                        maxEmptyCnt = emptyCnt;
                        loc = {j, i};
                    }
                }
            }
        }
        arr[loc.second][loc.first] = vec[0];
        locs.push_back(loc);
    }

    long long ans = 0;

    for (int i = 0; i < like.size(); i++) {
        vector<int> vec = like[i];
        pair<int, int> loc = locs[i];
        int x = loc.first;
        int y = loc.second;
        int cnt = 0;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            for (int l = 1; l < 5; l++) {
                if (arr[ny][nx] == vec[l]) {
                    ++cnt;
                    break;
                }
            }
        }
        if (cnt != 0) {
            ans += (long long)pow(10LL, cnt - 1);
        }
    }

    cout << ans;
}