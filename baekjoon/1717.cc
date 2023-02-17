#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<int> parent;
vector<int> weight;

int findRoot(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findRoot(parent[x]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n+1; i++) {
        parent.push_back(i);
        weight.push_back(1);
    }
    for(int i=0; i<m; i++) {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 0) {
            int x = findRoot(a);
            int y = findRoot(b);
            if ( x != y ) {

                if (weight[x] > weight[y]) swap(x, y);

                parent[x] = y;

                if (weight[x] == weight[y]) {
                    weight[y]++;
                }
                
            }
        }
        else {
            int x = findRoot(a);
            int y = findRoot(b);
            if ( x == y ) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
    }
}