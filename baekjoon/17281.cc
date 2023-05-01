#include <bits/stdc++.h>

using namespace std;
int N;
vector<vector<int>> arr;

int solve(int cur, int inning, vector<int>& seq) {
    if (inning > N) return 0;
    vector<int> status;
    int score = 0;
    int out = 0;
    while (out < 3) {
        int hit = arr[inning - 1][seq[cur]];
        if (hit == 0) {
            ++out;
        } else {
            vector<int> newStatus;
            for (int next : status) {
                if (next + hit > 3)
                    ++score;
                else
                    newStatus.push_back(next + hit);
            }
            status = newStatus;
            if(hit != 4)
                status.push_back(hit);
            else ++score;
        }
        ++cur;
        cur = cur % 9;
    }

    score += solve(cur, inning + 1, seq);

    return score;
}

int comb(int cnt, vector<int>& vis, vector<int>& seq) {
    if (cnt == 9) {
        return solve(0, 1, seq);
    }
    int ret = 0;
    for (int i = 0; i < 9; i++) {
        if(i == 0 && seq.size() != 3) continue;
        if (vis[i]) continue;
        vis[i] = 1;
        seq.push_back(i);
        ret = max(ret, comb(cnt + 1, vis, seq));
        seq.pop_back();
        vis[i] = 0;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            int t;
            cin >> t;
            arr[i].push_back(t);
        }
    }
    vector<int> vis(9, 0);
    vector<int> seq;
    cout << comb(0, vis, seq);
}