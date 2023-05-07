#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int n, m, q;
int id[505][505];
vector<vector<int>> heights;
int hh[505][505];
int seq[505][505];
int parent[250005];

int find(int cur) {
    if(cur == parent[cur]) return cur;
    return parent[cur] = find(parent[cur]);
}

bool compare(vi& a, vi& b) {
    return a[0] < b[0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n >> q;
    int idx = 1;

    for(int i=1; i<501; i++) for(int j=1; j<501; j++) id[i][j] = idx++;

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            int h; cin >> h;
            heights.push_back({h, j, i});
            hh[i][j] = h;
        }
    }

    sort(heights.begin(), heights.end(), compare);
    
    idx = 0;
    for(vi v : heights) {
        seq[v[2]][v[1]] = idx++;
    }

    vector<vector<int>> queries;
    for(int i=0; i<q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        queries.push_back({b, a, d, c});
    }

    vector<int> l;
    vector<int> r;
    for(int i=0; i<q; i++) {
        l.push_back(0);
        r.push_back(m*n-1);
    }

    vector<int> ans(q);

    // parellel binary search
    while(1) {
        vector<vector<int>> g(m*n+1);
        int flag = 0;
        for(int i=0; i<q; i++) {
            // 
            if(l[i] != r[i]) {
                flag = 1;
                // setting indiviaul binary search process
                g[(l[i] + r[i]) >> 1].push_back(i);
            }
        }
        if(!flag) break;

        // reset all disjoint set
        for(int i=0; i<250001; i++) parent[i] = i;

        for(int i=0; i<=m*n-1; i++) {
            int h = heights[i][0];
            int x = heights[i][1];
            int y = heights[i][2];
            int cur = id[y][x];
        
            for(int j=0; j<4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx<1||nx>n||ny<1||ny>m) continue;
                // continue when current height is lower than adjacent mountains height
                if(h < hh[ny][nx]) continue;
                int next = id[ny][nx];
                int fcur = find(cur);
                int fnext = find(next);

                // when parents are different let's merge
                if(fnext != fcur) {
                    //cout << "merge : " << x << " " << y << " to " << nx << " " << ny << '\n';
                    if(fcur > fnext) swap(fcur, fnext);
                    parent[fnext] = fcur;
                }
            }

            for(auto next : g[i]) {
                vi q = queries[next];
                int ax = q[0];
                int ay = q[1];
                int bx = q[2];
                int by = q[3];
                int aid = find(id[ay][ax]);
                int bid = find(id[by][bx]);
                //cout << aid << " " << bid << '\n';
                //cout << ax << " " << ay << " " << bx << " " <<by  << '\n';
                if(aid == bid) {
                    ans[next] = h;
                    r[next] = i;
                }
                else {
                    l[next] = i+1;
                }
            }
        }
    }

    for(int cur : ans) cout << cur << '\n';
}