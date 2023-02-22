#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<vector<char>> arr;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> M >> N;
    for(int i=0; i<M; i++) {
        vector<char> vec;
        for(int j=0; j<N; j++) {
            char tmp; cin >> tmp;
            int x;
            if(tmp == 'W') x = 0;
            else x = 1;
            vec.push_back(x);
        }
        arr.push_back(vec);
    }

    int minValue = 2500;

    for(int i=0; i<=M-8; i++) {
        for(int j=0; j<=N-8; j++) {
            // check board
            int cur = arr[i][j];
            int paint = 0;
            for(int m=i; m<i+8; m++) {
                for(int n=j; n<j+8; n++) {
                    if(cur != arr[m][n]) {
                      paint++;
                    }
                    cur = 1 - cur;
                }
                cur = 1 - cur;
            }
            int tmpMin = min(paint, 64 - paint);
            minValue = min(minValue, tmpMin);
        }
    }

    cout << minValue;
}