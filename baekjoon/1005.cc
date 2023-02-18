#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, K, W;
int estimate[1001];
bool visited[1001] = {false, };
vector<vector<int>> seq(1001);
vector<int> taskPriority;
int dp[1001];

void dfs(int x) {
    // 위상정렬
    visited[x] = true;
    
    for(int i=0; i<seq[x].size(); i++) {
        if(visited[seq[x][i]]) continue;
        dfs(seq[x][i]);
    }
    taskPriority.push_back(x);
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    for(; T>0; T--) {

        cin >> N >> K;

        taskPriority.clear();

        for(int i=1; i<N+1; i++) {
            cin >> estimate[i];
            visited[i] = false;
            dp[i] = estimate[i];

            vector<int> vec;
            seq[i] = vec;
        }

        for(int i=0; i<K; i++) {
            int x, y;
            cin >> x >> y;
            seq[x].push_back(y);
        }

        cin >> W;

        for(int i=1; i<N+1; i++) {
            if(!visited[i]) dfs(i);
        }

        reverse(taskPriority.begin(), taskPriority.end());

        for(int i=0; i<taskPriority.size(); i++) {
            int task = taskPriority[i];
            
            for(int j=0; j<seq[task].size(); j++) {
                int nextTask = seq[task][j];
                dp[nextTask] = max(dp[nextTask], dp[task] + estimate[nextTask]);
            }
        }

        cout << dp[W] << '\n';
    }
}