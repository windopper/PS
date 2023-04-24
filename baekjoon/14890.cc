#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> arr;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, L;
    cin >> N >> L;
    int ans = 0;
    arr.resize(N, vector<int>(N));
    for(int i=0; i<N; i++) {
        bool possible = true;
        bool need = false;
        int cont = 1;
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
            if(!possible) continue;
            if(j >= 1) {
                if(need && cont >= L) {
                    need = false;
                    cont = 0;
                }
                if(arr[i][j-1] - 1 == arr[i][j]) {
                    if(need) possible = false;
                    cont = 1;
                    need = true;
                }
                else if(arr[i][j-1] + 1 == arr[i][j]) {
                    if(need) possible = false;
                    if(cont >= L) {
                        cont = 1;
                    }
                    else {
                        possible = false;
                    }
                }
                else if(arr[i][j-1] == arr[i][j]) ++cont;
                else {
                    possible = false;
                }
            }
        }
        if(need && cont >= L) {
            possible = true;
        }
        else if(need && cont < L) possible = false;
        if(possible) {
            ++ans;
        }
    }

    for(int j=0; j<N; j++) {
        bool possible = true;
        bool need = false;
        int cont = 1;
        for(int i=0; i<N; i++) {
            if(i >= 1) {
                if(need && cont >= L) {
                    need = false;
                    cont = 0;
                }
                if(arr[i-1][j] - 1 == arr[i][j]) {
                    if(need) possible = false;
                    cont = 1;
                    need = true;
                }
                else if(arr[i-1][j] + 1 == arr[i][j]) {
                    if(need) possible = false;
                    if(cont >= L) {
                        cont = 1;
                    }
                    else {
                        possible = false;
                        break;
                    }
                }
                else if(arr[i-1][j] == arr[i][j]) ++cont;
                else {
                    possible = false;
                    break;
                }
            }
        }
        if(need && cont >= L) {
            possible = true;
        }
        else if(need && cont < L) possible = false;
        if(possible) {
            ++ans;
        }
    }

    cout << ans;
}