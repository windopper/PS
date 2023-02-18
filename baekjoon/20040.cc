#include <iostream>

using namespace std;
int n, m;
int parent[500002];
int cnt = 0;

int find(int x) {
    if( x == parent[x] ) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        parent[i] = i;
    }

    bool closed = false;

    for(int i=0; i<m; i++) {

        int a, b;
        cin >> a >> b;

        int x = find(a);
        int y = find(b);
        if ( x != y ) {
            if ( x < y ) {
                parent[y] = x;
            }
            else {
                parent[x] = y;
            }
        }
        else {
            cout << i+1;
            closed = true;
            break;
        }
    }

    if(!closed) cout << 0;

}