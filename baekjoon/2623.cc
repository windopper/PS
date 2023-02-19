#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
int N, M;
vector<vector<int>> graph;
int indegree[1001] = {0, };

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=1; i<N+1; i++) {
        vector<int> vec;
        graph.push_back(vec);
    }

    for(int i=0; i<M; i++) {
        int c;
        cin >> c;
        vector<int> v;

        for(int j=0; j<c; j++) {
            int tmp = 0;
            cin >> tmp;
            v.push_back(tmp);
        }

        for(int j=0; j<c-1; j++) {
            graph[v[j]].push_back(v[j+1]);
            indegree[v[j+1]]++;
        }
    }

    queue<int> q;
    queue<int> seq;
    for(int i=1; i<N+1; i++) {
        // indegree가 0인 노드들 q에 넣기
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        seq.push(node);
        for(int i=0; i<graph[node].size(); i++) {
            int nxt = graph[node][i];
            if(--indegree[nxt] == 0) q.push(nxt);
        }
    }

    if(seq.size() != N) {
        // 그래프에 사이클이 있을 때
        cout << 0;
        return 0;
    }

    while (!seq.empty()) {
        cout << seq.front() << "\n";
        seq.pop();
    }

}
