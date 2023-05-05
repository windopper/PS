#include <bits/stdc++.h>

using namespace std;
const int MOD = 10007;
int R, S;
string arr;
unordered_map<int, unordered_map<int, int>> dp[100];
//int dp[100][1000][1000];

int convertToMask(vector<int>& arr) {
    int res = 0;
    for(int i=0, c=1; i<S; i++, c*=10) {
        res += arr[i] * c;
    }
    return res;
}

vector<int> norm(vector<int>& arr) {
    vector<int> ret(S);
    unordered_map<int, int> us;
    int t = 1;
    for(int i=0; i<S; i++) {
        if(arr[i] == 0) continue;
        if(us.find(arr[i]) == us.end()) us[arr[i]] = t++;
        ret[i] = us[arr[i]];
    }
    return ret;
}

bool hasUpAlone(vector<int>& arr) {
    for(int i=0; i<S-1; i++) {
        if(arr[i] == arr.back()) return false;
    }
    return true;
}

bool checkConnected(int connection) {
    vector<int> status(S, 0);
    for(int i=0; i<S; i++) {
        status[i] = connection%10;
        connection/=10;
    }
    unordered_set<int> us;
    for(int x : status) {
        if(x) us.insert(x);
    }
    if(us.size() == 1) return true;
    return false;
}

int solve(int cur, int st, int con) {
    if(cur == R*S) {
        if(!checkConnected(con)) return 0;
        vector<int> status(S);
        for(int i=0; i<S; i++) {
            status[i] = st%10;
            st/=10;
        }
        int back = status.back();
        if(back == 1 || back == 2 || back == 4 || back == 5 || back == 6) return 0;
        for(int i=1; i<S-1; i++) {
            int last = status[i];
            if(last == 4 || last == 5 || last == 6) return 0;
        }
        int first = status[0];
        if(first == 1 || first == 2 || first == 3 || first == 6 || first == 0) return 0;
        return 1;
    }

    if(dp[cur].find(st) != dp[cur].end() && dp[cur][st].find(con) != dp[cur][st].end()) return dp[cur][st][con];
    dp[cur][st][con] = 0;
    int &ret = dp[cur][st][con];

    vector<int> status(S);
    for(int i=0; i<S; i++) {
        status[i] = st%10;
        st/=10;
    }

    vector<int> connection(S);
    for(int i=0; i<S; i++) {
        connection[i] = con%10;
        con/=10;
    }

    vector<int> nextArr(S);
    for(int i=1; i<S; i++) nextArr[i] = status[i-1];

    vector<int> nextConnection(S);
    for(int i=1; i<S; i++) nextConnection[i] = connection[i-1];

    int upCon = connection.back();
    int leftCon = cur % S ? connection[0] : 0;

    int up = status.back();
    int left = cur % S ? status[0] : 0;

    if(arr[cur] == '#') {
        if(left == 1 || left == 3 || left == 6) return 0;
        if(up >= 4 && up <= 6) return 0;
        if(!(upCon && hasUpAlone(connection))) {
            nextArr[0] = 0;
            nextConnection[0] = 0;
            vector<int> temp = norm(nextConnection);
            ret += solve(cur + 1, convertToMask(nextArr), convertToMask(temp));
        }
        return ret;
    }

    // 위쪽과 연결할 수 있다면
    if(up >= 4 && up <= 6) {
        // 왼쪽도 연결 할 수 있다면
        if(left == 1 || left == 3 || left == 6) {
            vector<int> newArr = nextArr;
            vector<int> newConnection = nextConnection;
            newArr[0] = 2;
            newConnection[0] = upCon;
            for(int i=1; i<S; i++) if(newConnection[i] == leftCon) newConnection[i] = upCon;
            vector<int> temp = norm(newConnection);
            ret += solve(cur + 1, convertToMask(newArr), convertToMask(temp));
        }
        // 왼쪽은 연결 할 수 없다면
        else {
            vector<int> newArr = nextArr;
            vector<int> newConnection = nextConnection;
            newConnection[0] = upCon;
            vector<int> temp = norm(newConnection);
            int connectionMask = convertToMask(temp);

            if(cur % S != S-1) {
                newArr[0] = 3;
                ret += solve(cur + 1, convertToMask(newArr), connectionMask);
            }
            newArr[0] = 4;
            ret += solve(cur + 1, convertToMask(newArr), connectionMask);
        }
    }
    // 왼쪽과 연결할 수 있다면
    if(left == 1 || left == 3 || left == 6) {
        // 위쪽은 연결 할 수 없다면
        if(up <= 3) {
            vector<int> newArr = nextArr;
            vector<int> newConnection = nextConnection;
            newConnection[0] = leftCon;
            vector<int> temp = norm(newConnection);
            int connectionMask = convertToMask(temp);

            if(cur % S != S-1) {
                newArr[0] = 1;
                ret += solve(cur + 1, convertToMask(newArr), connectionMask);
            }

            newArr[0] = 5;
            ret += solve(cur + 1, convertToMask(newArr), connectionMask);
        }
    }
    // 둘다 연결할 수 없다면
    if((left == 2 || left == 4 || left == 5 || left == 0) && (up == 1 || up == 2 || up == 3 || up == 0)) {
        vector<int> newArr = nextArr;
        vector<int> newConnection = nextConnection;
        newArr[0] = 0;
        newConnection[0] = 0;
        vector<int> temp = norm(newConnection);
        int connectionMask = convertToMask(temp);
        
        ret += solve(cur + 1, convertToMask(newArr), connectionMask);

        if(cur % S != S-1) {
            newArr[0] = 6;
            newConnection[0] = 1234;
            temp = norm(newConnection);
            connectionMask = convertToMask(temp);
            ret += solve(cur + 1, convertToMask(newArr), connectionMask);
        }
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
    cout << solve(1, 3, 1) + solve(1, 4, 1);
}