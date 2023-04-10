#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K;
    cin >> N >> K;
    string arr;
    cin >> arr;
    int vis[20001] = {0, };
    int cnt = 0;
    for(int i=0; i<N; i++) {
        if(arr[i] == 'P') {
            for(int j=-K; j<=K; j++) {
                if(i+j >=0 && i+j < N) {
                    if(arr[i+j] == 'H' && vis[i+j] == 0) {
                        vis[i+j] = 1;
                        ++cnt;
                        break;
                    }
                }
            }
        }
    }

    cout << cnt;
}