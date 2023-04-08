#include <bits/stdc++.h>

using namespace std;

int N;
void click(int v, string& cur) {
    for (int i = -1; i < 2; i++) {
        if (v + i < 0 || v + i >= N) continue;
        cur[v + i] = cur[v + i] == '0' ? '1' : '0';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string cur, target;
    cin >> N;
    cin >> cur >> target;

    int result = numeric_limits<int>::max();
    int ans1 = 0;
    string copied = cur;
    click(0, copied);
    ++ans1;
    for (int i = 1; i < N - 1; i++) {
        if (copied == target) break;
        if (copied[i - 1] == target[i - 1]) continue;
        click(i, copied);
        ++ans1;
    }


    if (copied != target) {
        click(N - 1, copied);
        ++ans1;
    }
    if (copied == target) {
        result = ans1;
    }

    copied = cur;
    int ans2 = 0;
    for (int i = 1; i < N - 1; i++) {
        if (copied == target) break;
        if (copied[i - 1] == target[i - 1]) continue;
        click(i, copied);
        ++ans2;
    }

    if (copied != target) {
        click(N - 1, copied);
        ++ans2;
    }
    if (copied == target) {
        result = min(result, ans2);
    }

    if(result == numeric_limits<int>::max()) result = -1;
    cout << result;
    return 0;
}