#include <bits/stdc++.h>

using namespace std;
const int INF = 1000000000;
vector<int> powers;

int solve(int target) {
    int mul = 1;
    for (int i = 0; i < powers.size(); i++) {
        if (target >= powers[i] * mul - 1) {
            ++target;
            continue;
        }

        if (i == 0) return target;

        ++mul;
        i = 0;
    }
    return target;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int K;
    cin >> K;
    for (int i = 2; i <= floor(sqrt(INF)); ++i) {
        powers.push_back(pow(i, 2));
    }
    cout << solve(K);
}