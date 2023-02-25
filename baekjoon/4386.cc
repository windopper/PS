#include <bits/stdc++.h>

using namespace std;
int n;
vector<pair<double, double>> arr;
vector<pair<double, pair<int, int>>> edges;
int parent[100];

int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) {
        parent[i] = i;
        double x, y;
        cin >> x >> y;
        arr.push_back({x, y});
    }

    for(int i=0; i<n; i++) {
        double x1 = arr[i].first;
        double y1 = arr[i].second;
        for(int j=i+1; j<n; j++) {
            double x2 = arr[j].first;
            double y2 = arr[j].second;
            double d = dist(x1, y1, x2, y2);
            edges.push_back({d, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());
    double ans = 0;
    for(int i=0; i<edges.size(); i++) {
        double d = edges[i].first;
        int s = edges[i].second.first;
        int e = edges[i].second.second;
        s = find(s);
        e = find(e);
        if(s != e) {
            if(s < e) parent[e] = s;
            else parent[s] = e;
            ans += d;
        }
    }

    cout << ans;
}