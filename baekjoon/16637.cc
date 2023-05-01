#include <bits/stdc++.h>

using namespace std;
int N;
int num[20];
char op[20];

long long solve(int cur, long long val) {
    
    if (cur >= N/2+1) {
        return val;
    }
    long long ret = numeric_limits<long long>::min();

    // 단일
    if (op[cur] == '+') {
        ret = max(ret, solve(cur + 1, val + num[cur]));
    } else if (op[cur] == '*') {
        ret = max(ret, solve(cur + 1, val * num[cur]));
    } else if (op[cur] == '-') {
        ret = max(ret, solve(cur + 1, val - num[cur]));
    }

    // 두개
    if (cur + 1 < N/2+1) {
        long long tmp;

        if (op[cur + 1] == '+')
            tmp = num[cur] + num[cur + 1];
        else if (op[cur + 1] == '*')
            tmp = num[cur] * num[cur + 1];
        else if (op[cur + 1] == '-')
            tmp = num[cur] - num[cur + 1];

        if (op[cur] == '+') {
            ret = max(ret, solve(cur + 2, val + tmp));
        } else if (op[cur] == '*') {
            ret = max(ret, solve(cur + 2, val * tmp));
        } else if (op[cur] == '-') {
            ret = max(ret, solve(cur + 2, val - tmp));
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    string s;
    cin >> s;
    op[0] = '+';
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            num[i / 2] = s[i] - '0';
        } else {
            op[i / 2 + 1] = s[i];
        }
    }

    cout << solve(0, 0);
}