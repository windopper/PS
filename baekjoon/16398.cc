#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<pair<int, pair<int, int>>> q;
int parents[1001];

int find(int x) {
    if(x == parents[x]) return x;
    return parents[x] = find(parents[x]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        parents[i] = i;
        for(int j=0; j<N; j++) {
            int a;
            cin >> a;
            if(i == j) continue;
            q.push_back({a, {i, j}});
        }
    }
    sort(q.begin(), q.end());
    long long ans = 0;
    for(int i=0; i<q.size(); i++) {
        int cost = q[i].first;
        int a = q[i].second.first;
        int b = q[i].second.second;
        a = find(a);
        b = find(b);
        if(a != b) {
            if( a < b ) {
                parents[b] = a;
            }
            else {
                parents[a] = b;
            }
            ans += (long long) cost;
        }
    }
    cout << ans;
}
