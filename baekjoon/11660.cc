#include <bits/stdc++.h>

using namespace std;
int csum[1025][1025];
int arr[1025][1025];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i=1; i<N+1; i++) {
        for(int j=1; j<N+1; j++) {
            int v;
            cin >> v;
            arr[i][j] = v;

            csum[i][j] = arr[i][j] + csum[i-1][j] + csum[i][j-1] - csum[i-1][j-1];
        }
    }

    for(int i=0; i<M; i++) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        cout << csum[y2][x2] - csum[y2][x1-1] - csum[y1-1][x2] + csum[y1-1][x1-1] << "\n";
    }
}