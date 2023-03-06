#include <bits/stdc++.h>

using namespace std;

void randomAssign(int& a, int& b, int& c, int& d) {
    if (a == 0) a = 1;
    if (b == 0) b = 1;
    if (c == 0) c = 1;
    if (d == 0) d = 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> arr(N + 1);
    arr[0] = 0;
    for (int i = 0; i < N; i++) cin >> arr[i + 1];
    vector<int> copied(arr);

    int lleft = 0, lright = 0;
    for (int i = 1; i < N + 1; i++) {
        if (arr[i] == i) continue;
        if (lleft == 0) {
            lleft = i;
            continue;
        }
        if (lleft == arr[i]) {
            lright = i;
            break;
        }
    }

    reverse(arr.begin() + lleft, arr.begin() + lright + 1);

    int rleft = 0, rright = 0;
    for (int i = N; i > 0; i--) {
        if (arr[i] == i) continue;
        if (rright == 0) {
            rright = i;
            continue;
        }
        if (rright == arr[i]) {
            rleft = i;
            break;
        }
    }

    reverse(arr.begin() + rleft, arr.begin() + rright + 1);

    bool isCorrect = true;
    for (int i = 1; i < N + 1; i++) {
        if (arr[i] != i) isCorrect = false;
    }
    if (isCorrect) {
        randomAssign(lleft, lright, rleft, rright);
        cout << lleft << " " << lright << "\n" << rleft << " " << rright;
        return 0;
    }

    arr = copied;

    rleft = 0, rright = 0;
    for (int i = N; i > 0; i--) {
        if (arr[i] == i) continue;
        if (rright == 0) {
            rright = i;
            continue;
        }
        if (rright == arr[i]) {
            rleft = i;
            break;
        }
    }

    reverse(arr.begin() + rleft, arr.begin() + rright + 1);

    lleft = 0, lright = 0;
    for (int i = 1; i < N + 1; i++) {
        if (arr[i] == i) continue;
        if (lleft == 0) {
            lleft = i;
            continue;
        }
        if (lleft == arr[i]) {
            lright = i;
            break;
        }
    }

    reverse(arr.begin() + lleft, arr.begin() + lright + 1);

    isCorrect = true;
    for (int i = 1; i < N + 1; i++) {
        if (arr[i] != i) isCorrect = false;
    }
    if (isCorrect) {
        randomAssign(lleft, lright, rleft, rright);
        cout << rleft << " " << rright << "\n" << lleft << " " << lright;
        return 0;
    }
}