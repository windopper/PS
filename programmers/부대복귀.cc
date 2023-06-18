#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {

    vector<vector<int>> path(n+1);
    for(auto road : roads) {
        path[road[0]].push_back(road[1]);
        path[road[1]].push_back(road[0]);
    }

    queue<int> q;
    vector<int> dist(100001, INF);
    q.push(destination);
    dist[destination] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int next : path[cur]) {
            if(dist[next] > dist[cur] + 1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }

    vector<int> answer;
    for(int source : sources) {
        answer.push_back(dist[source] != INF ? dist[source] : -1);
    }
    return answer;
}