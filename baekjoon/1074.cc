#include <bits/stdc++.h>

using namespace std;
int N, r, c;
int cnt = 0;
int answer = -1;

// solve(0, 0, 4) -> solve(0, 0, 2) -> solve(1, 1, 1)

void solve(int x, int y, int move) {
    //cout << x << " " << y << " " << move << " " << cnt << '\n';
    if(answer != -1) return;
    if(x == c && r == y) {
        answer = cnt;
        return;
    }
    if(move == 0) {
        ++cnt;
        return;
    }
    
    if(x <= c && c < x + move && y <= r && r < y + move) {
        solve(x, y , move / 2);
    }
    else if(x + move <= c && c < x + 2 * move && y <= r && r < y + move) {
        cnt += move * move;
        solve(x + move, y, move / 2);
    }
    else if(x <= c && c < x + move && y + move <= r && r < y + 2 * move) {
        cnt += 2 * move * move;
        solve(x, y + move, move / 2);
    }
    else {
        cnt += 3 * move * move;
        solve(x + move, y + move , move / 2);
    }
}

int main() {
    cin >> N >> r >> c;
    long long start = pow(2, N) / 2;
    solve(0, 0, start);
    cout << answer;
}