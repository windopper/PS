#include <bits/stdc++.h>

using namespace std;
int N, M;
int parent[1000000];
vector<vector<int>> arr;

pair<int, int> getMove(char x) {
    switch(x) {
        case 'D':
        return make_pair(0, 1);
        case 'U':
        return make_pair(0, -1);
        case 'L':
        return make_pair(-1, 0);
        case 'R':
        return make_pair(1, 0);
    }
    return make_pair(0, 0);
}

int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void dfs(int x, int y) {
    pair<int, int> move = getMove(arr[y][x]);
    int nx = x + move.first;
    int ny = y + move.second;
    int f1 = find(y*M+x);
    int f2 = find(ny*M+nx);
    if(f1 != f2) {
        parent[f1] = f2;
    }
    else {
        return;
    }
    dfs(nx, ny);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        vector<int> vec;
        for(int j=0; j<M; j++) {
            char x;
            cin >> x;
            vec.push_back(x);
            parent[i*M+j] = i*M+j;
        }
        arr.push_back(vec);
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            dfs(j, i);
        }
    }

    int ans[1000000] = {0, };
    int cnt = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            int f = find(i*M+j);
            if(ans[f] == 0) {
                cnt++;
                ans[f] = 1;
            }
        }
    }

    cout << cnt;
}