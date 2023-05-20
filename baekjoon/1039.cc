#include <bits/stdc++.h>

using namespace std;

string answer = "-1";
string s;
int K;

void bfs() {
    queue<pair<string, int>> q;
    q.push({s, 0});
    vector<vector<int>> vis(1000001, vector<int>(11, 0));

    while(!q.empty()) {
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cur[0] == '0') continue;
        if(cnt == K) {
            answer = max(answer, cur);
            continue;
        }
        for(int i=0; i<s.size(); i++) {
            for(int j=i+1; j<s.size(); j++) {
                string next = cur;
                swap(next[i], next[j]);
                if(vis[stoi(next)][cnt+1]) continue;
                vis[stoi(next)][cnt+1] = 1;
                q.push({next, cnt + 1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> K;
    vector<pair<int ,int>> q;
    bfs();
    cout << answer;
}