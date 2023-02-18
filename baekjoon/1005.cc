#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, K, W;
int estimate[1001];
bool visited[1001] = {false, };
vector<vector<int>> seq(1001);
vector<int> taskPriority;

void dfs(int x) {
    
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

        for(int i=1; i<N+1; i++) {
            cin >> estimate[i];
            visited[i] = false;
        }
        for(int i=1; i<K+1; i++) {
            vector<int> vec;
            seq[i] = vec;
        }

        for(int i=0; i<K; i++) {
            int x, y;
            cin >> x >> y;
            seq[x].push_back(y);
        }

        cin >> W;

        for(int i=1; i<W+1; i++) {
            if(!visited[i]) dfs(i);
        }

        reverse(taskPriority.begin(), taskPriority.end());

        for(int i=0; i<taskPriority.size(); i++) {
            cout << taskPriority[i] << " ";
        }
        cout << endl;
    }
}