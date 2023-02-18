#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M;
set<int> nodes[10001];
set<int> visited;
int weight[10001][10001];

int find(int start, int cur, int end) {
    cout << start << " " << cur << " " << end << "\n";
    if ( cur == end ) return weight[start][end];
    visited.insert(cur);
    int maxValue = 0;
    for(set<int>::iterator iter=nodes[cur].begin(); iter!=nodes[cur].end(); iter++) {
        set<int>::iterator fiter = visited.find(*iter);
        if(fiter == visited.end()) {
            continue;
        }
        maxValue = max(maxValue, find(start, *iter, end));
    }
    return maxValue;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=1; i<N+1; i++) {
        set<int> vec;
        nodes[i] = vec;
    }
    for(int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        weight[a][b] = c;
        weight[b][a] = c;
        nodes[a].insert(b);
        nodes[b].insert(a);
    }

    int x, y;
    cin >> x >> y;
    int ans = find(x, x, y);
    cout << ans;
}