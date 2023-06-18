#include <bits/stdc++.h>

using namespace std;
long long dp[500001];

long long solve(vector<int>& seq) {
    dp[0] = (long long)seq[0];
    long long ret = dp[0];
    for(int i=1; i<seq.size(); i++) {
        dp[i] = max((long long)0, dp[i-1]) + seq[i];
        ret = max(ret, dp[i]);
    }
    return ret;
}

long long solution(vector<int> sequence) {
    memset(dp, -1, sizeof(dp));
    long long ans = 0;
    vector<int> seq1;
    int mul = -1;
    for(auto i : sequence) {
        seq1.push_back(i * mul);
        mul *= -1;
    }
    ans = max(ans, solve(seq1));

    memset(dp, -1, sizeof(dp));
    vector<int> seq2;
    mul = 1;
    for(auto i : sequence) {
        seq2.push_back(i * mul);
        mul *= -1;
    }
    ans = max(ans, solve(seq2));
    return ans;
}