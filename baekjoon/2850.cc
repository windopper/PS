#include <bits/stdc++.h>

using namespace std;
const int MOD = 10007;
int R, S;
string arr;
unordered_map<long long, int> dp[100];
//int dp[100][1000][1000];

long long convertToMask(vector<int>& arr) {
    long long res = 0;
    for(long long i=0, c=1; i<S+1; i++, c*=10) {
        res += (long long)arr[i] * c;
    }
    return res;
}

vector<int> norm(vector<int>& arr) {
    vector<int> ret(S+1);
    int chk[10] = {0, };
    int t = 1;
    for(int i=0; i<S+1; i++) {
        if(arr[i] == 0) continue;
        if(chk[arr[i]] == 0) chk[arr[i]] = t++;
        ret[i] = chk[arr[i]];
    }
    return ret;
}

int solve(int cur, long long st) {
    vector<int> status(S+1, 0);
    for(int i=0; i<S+1 && st; i++) {
        status[i] = st%10LL;
        st/=10LL;
    }
    status = norm(status);
    st = convertToMask(status);

    if(cur == R*S) {
        // [0, 0, 0, .... 0, 1, 0]
        if(st == 10) {
            return 1;
        }
        return 0;
    }

    if(dp[cur].find(st) != dp[cur].end()) return dp[cur][st];
    dp[cur][st] = 0;
    int &ret = dp[cur][st];

    vector<int> nextArr(S+1, 0);
    for(int i=2; i<S+1; i++) nextArr[i] = status[i-1];

    int up = status.back();
    int left = cur % S ? status[0] : 0;

    if(cur % S == 0 && status[0] > 0) return 0;
    if(arr[cur] == '#') {
        if(left || up) return 0;
        nextArr[0] = 0;
        nextArr[1] = 0;
        ret += solve(cur + 1, convertToMask(nextArr));
        ret %= MOD;
        return ret;
    }

    // 위쪽과 연결할 수 있을 때
    if(up) {
        // 왼쪽과 연결 할 수 있을 때
        if(left) {
            if(up != left) {
                vector<int> newArr = nextArr;
                newArr[0] = 0;
                newArr[1] = 0;
                for(int i=2; i<S+1; i++) if(newArr[i] == left) newArr[i] = up;
                ret += solve(cur + 1, convertToMask(newArr));
            }
        }
        // 왼쪽과 연결 할 수 없을 때
        else {
            nextArr[0] = 0;
            nextArr[1] = up;
            ret += solve(cur + 1, convertToMask(nextArr));

            nextArr[0] = up;
            nextArr[1] = 0;
            ret += solve(cur + 1, convertToMask(nextArr));
        }
    }

    // 왼쪽과 연결 할 수 있을 때
    else if(left) {
        nextArr[0] = left;
        nextArr[1] = 0;
        ret += solve(cur + 1, convertToMask(nextArr));

        nextArr[0] = 0;
        nextArr[1] = left;
        ret += solve(cur + 1, convertToMask(nextArr));
    }

    // 둘다 연결 할 수 없다면?
    else {
        nextArr[0] = 9;
        nextArr[1] = 9;
        ret += solve(cur + 1, convertToMask(nextArr));

        nextArr[0] = 0;
        nextArr[1] = 0;
        ret += solve(cur + 1, convertToMask(nextArr));
    }
    ret %= MOD;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> S;
    for(int i=0; i<R; i++) {
        string s; cin >> s;
        arr += s;
    }
    vector<int> arr(S+1, 0);
    arr[S] = 1;
    cout << solve(0, convertToMask(arr));
}