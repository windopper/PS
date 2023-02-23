#include <bits/stdc++.h>

using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int R, C, T;
vector<vector<int>> arr;
vector<pair<int, int>> airCondition;

void diffusion(vector<vector<int>>& arr) {

    int addition[R][C];
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) addition[i][j] = 0;
    }

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(arr[i][j] > 0) {
                int diffusionAmount = arr[i][j] / 5;
                int diffusionCnt = 0;
                for(int k=0; k<4; k++) {
                    int nx = dx[k] + j;
                    int ny = dy[k] + i;
                    if(nx>=0 && nx<C && ny>=0 && ny<R && arr[ny][nx] >= 0) {
                        addition[ny][nx] += diffusionAmount;
                        diffusionCnt ++;
                    }
                }
                arr[i][j] = arr[i][j] - diffusionAmount * diffusionCnt; 
            }
        }
    }

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(arr[i][j] >= 0) {
                arr[i][j] += addition[i][j];
            }
        }
    }
}

void purification(vector<vector<int>>& arr) {
    int future[R][C];
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            future[i][j] = -1;
        }
    }
    int y1 = airCondition[0].first;
    int x1 = airCondition[0].second;
    int y2 = airCondition[1].first;
    int x2 = airCondition[1].second;

    for(int i=0; i<C-1; i++) {
        int tmp = arr[y1][i];
        if(tmp == -1) tmp = 0;
        future[y1][i+1] = tmp;
    }

    for(int i=y1; i>0; i--) {
        future[i-1][C-1] = arr[i][C-1];
    }

    for(int i=C-1; i>0; i--) {
        future[0][i-1] = arr[0][i];
    }

    for(int i=0; i<y1; i++) {
        future[i+1][0] = arr[i][0];
    }

    // second
    for(int i=0; i<C-1; i++) {
        int tmp = arr[y2][i];
        if(tmp == -1) tmp = 0;
        future[y2][i+1] = tmp;
    }

    for(int i=y2; i<R-1; i++) {
        future[i+1][C-1] = arr[i][C-1];
    }

    for(int i=C-1; i>0; i--) {
        future[R-1][i-1] = arr[R-1][i];
    }

    for(int i=R-1; i>y2; i--) {
        future[i-1][0] = arr[i][0];
    }

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(arr[i][j] >= 0 && future[i][j] != -1) arr[i][j] = future[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C >> T;
    for(int i=0; i<R; i++) {
        vector<int> vec;
        int tmp;
        for(int j=0; j<C; j++) {
            cin >> tmp;
            vec.push_back(tmp);
            if(tmp == -1) {
                airCondition.push_back({i, j});
            }
        }
        arr.push_back(vec);
    }

    for(; T>0; T--) {
        diffusion(arr);
        purification(arr);
    }
    int sum = 0;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(arr[i][j] == -1) continue;
            sum += arr[i][j];
        }
    }
    cout << sum;
}