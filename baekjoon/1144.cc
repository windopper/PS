#include <bits/stdc++.h>

using namespace std;
int N, M;
int arr[81];
unordered_map<int, int> dp[81];

int solve(int cur, int val) {
    if(cur > N*M) return 0;

    if(dp[cur].find(val) != dp[cur].end()) return dp[cur];
    int &ret = dp[cur][val];
    ret = 987654321;

    vector<int> state(M);
    for(int i=0; i<M && val; i++) {
        s[i] = val % 10;
        val /= 10;
    }

    // 현재 칸에 추가하는 경우
    vector<int> nextArr;
    for(int i=1; i<M; i++) nextArr[i] = state[i-1];
    int up = state.back();
    int left = cur % M ? s[0] : 0;
    // 윗칸이랑 합칠때
    if(up) {
        nextArr[0] = up;
        // 옆칸도 있으면 같은 칸으로 결합
        if(left) for(int i=1; i<M; i++) if(nextArr[i] == left) nextArr[i] = up;
    }
    else if(left) {
        nextArr[0] = left;
    }
    else {
        nextArr[0] = 999;
    }

    // renumbering
    unordered_map<int, int> sq;
    for(int i=0, t=1; i<M; i++) {
        if(nextArr[i] == 0) continue;
        if(sq.find(nextArr[i]) == ck.end()) ck[nextArr[i]] = t++;
        nextArr[i] = ck[nextArr[i]];
    }

    // 재결합
    int nextVal = 0;
    for(int i=0, c=1; i<M; i++, c*=10) {
        nextVal += nextArr[i] * c;
    }

    ret = min(ret, solve(cur + 1, nextVal) + mat[cur]);

    // 현재 칸에 추가하지 않는 경우
    bool UpAlone = true;
    for(int i=1; i<M-1; i++) if(state[i] == state.back()) {
        UpAlone = false;
        break;
    }
    if(state[M-1] || !UpAlone) {
        nextArr[0] = 0;
        unordered_map<int, int> sq;
        for(int i=0, t=1; i<M; i++) {
            if(nextArr[i] == 0) continue;
            if(sq.find(nextArr[i]) == ck.end()) ck[nextArr[i]] = t++;
            nextArr[i] = ck[nextArr[i]];
        }
        nextVal = 0;
        for(int i=0, c=1; i<M; i++, c*=10) {
            nextVal += nextArr[i] * c;
        }
        ret = min(ret, solve(cur + 1, nextVal));
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> arr[i][j];
    }
    cout << solve(0, 0);
}