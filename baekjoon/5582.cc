#include <bits/stdc++.h>

using namespace std;

int dp[4001][4001];

string str1, str2;
int solve(int s1, int s2) {
    if (s1 == str1.size() - 1 || s2 == str2.size() - 1) return 0;
    int &ret = dp[s1][s2];
    if (ret != -1) return ret;
    ret = 0;
    if (str1[s1 + 1] == str2[s2 + 1]) {
        ret = max(ret, solve(s1 + 1, s2 + 1) + 1);
    } else {
        ret = max(ret, solve(s1 + 1, s2));
        ret = max(ret, solve(s1, s2 + 1));
    }
    return ret;
}

int solve2(int a, int b) {
    if (a == 0 || b == 0) return 0;
    int &ret = dp[a][b];
    if (ret != -1) return ret;
    if (str1[a-1] == str2[b-1]) {
        ret = solve2(a-1, b-1) + 1;
    }
    else {
        ret = max(solve2(a-1, b), solve2(a, b-1));
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> str1 >> str2;
    cout << solve2(str1.size(), str2.size());

    for (int i=0; i<str1.size(); i++) {
        for (int j=0; j<str2.size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}