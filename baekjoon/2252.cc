#include <iostream>
#include <map>
#include <vector>

using namespace std;
int N, M;
map<int, vector<int>> arr;
bool visited[32001] = { false, };
vector<int> path;

void dfs(int i) {

    visited[i] = true;
    for(int j=0; j<arr[i].size(); j++) {
        if(visited[arr[i][j]]) continue;
        dfs(arr[i][j]);
    }
    path.push_back(i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        vector<int> vec;
        arr[i] = vec;
    }
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
    }

    for(int i=1; i<N+1; i++) {
        if(visited[i]) continue;
        dfs(i);
    }

    for(int i=N-1; i>=0; i--) {
        cout << path[i] << " ";
    }
}