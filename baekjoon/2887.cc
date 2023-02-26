#include <bits/stdc++.h>

using namespace std;
int N;
vector<vector<int>> arr;
vector<pair<int, pair<int, int>>> edges;
vector<int> parent;

int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        int x, y ,z;
        cin >> x >> y >> z;
        arr.push_back({x, y, z});
    }

    sort(arr.begin(), arr.end());

    for(int i=0; i<arr.size(); i++) {
        for(int j=i+1; j<arr.size(); j++) {
            int temp = min(abs(arr[i][0]-arr[j][0]), abs(arr[i][1]-arr[j][1]));
            int dist = min(temp, abs(arr[i][2]-arr[j][2]));
            edges.push_back({dist, {i, j}}); 
        }
    }
    sort(edges.begin(), edges.end());
    vector<pair<int, pair<int, int>>> pq;
    for(int i=0; i<N; i++) {
        pq.push_back(edges[i]);
    }
    parent.resize(pq.size());

    for(int i=0; i<parent.size(); i++) {
        parent[i] = i;
    }

    int ans = 0;
    for(int i=0; i<pq.size(); i++) {
        int dist = pq[i].first;
        int s = pq[i].second.first;
        int e = pq[i].second.second;
        s = find(s);
        e = find(e);
        if(s != e) {
            if(e < s) swap(s, e);
            parent[e] = s;
            ans += dist;
        }
    }
    cout << ans;
}