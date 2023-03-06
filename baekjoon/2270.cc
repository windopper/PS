#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int cnt[3];
    cin >> n;
    for (int i = 0; i < 3; i++) cin >> cnt[i];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            int temp;
            cin >> temp;
        }
    }
    int stickNumber = -1;
    int minimumMoves = 1000000;

    for (int i = 0; i < 3; i++) {
        int moves = 0;
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            moves += ((long long)(pow(2, cnt[j]) - 1) % 1000000);
        }
        if (minimumMoves > moves) {
            minimumMoves = moves;
            stickNumber = i + 1;
        }
    }

    cout << stickNumber << "\n" << minimumMoves;
}