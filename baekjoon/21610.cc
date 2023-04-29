#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
vector<vector<int>> arr;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    arr.resize(N+1, vector<int>(N+1));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }

    vector<pair<int, int>> clouds;
    for(int i=0; i<M; i++) {
        int d, s;
        cin >> d >> s;
        --d;
        if(i == 0) {
            clouds = {{0, N-1}, {1, N-1}, {0, N-2}, {1, N-2}};
        }

        vector<vector<int>> isCloudExistBefore(N, vector<int>(N, 0));
        //moves and add water
        for(pii& cloud : clouds) {
            int x = cloud.first;
            int y = cloud.second;
            int newX = (x + N * 50 + dx[d] * s) % N;
            int newY = (y + N * 50 + dy[d] * s) % N;
            arr[newY][newX]++;
            isCloudExistBefore[newY][newX] = 1;
        }

        clouds.clear();

        vector<vector<int>> incs(N, vector<int>(N, 0));

        // water duping
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(!isCloudExistBefore[i][j]) continue;
                int cnt = 0;
                for(int k=1; k<=7; k+=2) {
                    int nx = j + dx[k];
                    int ny = i + dy[k];
                    if(nx<0||nx>=N||ny<0||ny>=N) continue;
                    if(arr[ny][nx]) ++cnt;
                }
                incs[i][j] = cnt;
            }
        }

        // water duping and create clouds
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(incs[i][j]) arr[i][j] += incs[i][j];
                if(isCloudExistBefore[i][j]) continue;
                if(arr[i][j] >= 2) {
                    clouds.push_back({j, i});
                    arr[i][j] -= 2;
                }
            }
        }
    }

    long long ret = 0;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) ret += arr[i][j];
    }

    cout << ret;
}