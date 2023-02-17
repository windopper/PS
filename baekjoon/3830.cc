#include <iostream>
#include <vector>

using namespace std;
int N, M;
int parent[100001];
int weight[100001];

int find(int x) {
    if ( x == parent[x]) return x;
    int tmp = find(parent[x]);
    weight[x] += weight[parent[x]];
    return parent[x] = tmp;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (true) {
        cin >> N >> M;
        if( N == 0 && M == 0 ) break;

        for(int i=1; i<N+1; i++) {
            parent[i] = i;
            weight[i] = 0;
        }

        for(int i=0; i<M; i++) {
            char q;
            int a, b;
            int w;

            cin >> q >> a >> b;

            bool possible = true;
            
            if(q == '!') {
                cin >> w;
                int x = find(a);
                int y = find(b);
                if ( x != y ) {
                    parent[y] = x;
                    weight[y] = weight[a] - weight[b] + w;
                }
            }
            else {
                int x = find(a);
                int y = find(b);
                if ( x != y ) {
                    cout << "UNKNOWN" << "\n";
                }
                else {
                    cout << weight[b] - weight[a] << "\n";
                }
            }
        }
    }

    return 0;
}