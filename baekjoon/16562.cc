#include <iostream>
#include <set>

using namespace std;
int N, M, k;
int A[10001];
int parent[10001];

int find(int x) {
    if ( x == parent[x] ) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> k;
    for(int i=1; i<N+1; i++) { 
        cin >> A[i];
        parent[i] = i;
    }
    for(int i=0; i<M; i++) {
        int v, w;
        cin >> v >> w;

        int x = find(v);
        int y = find(w);
        if ( x != y ) {
            if ( A[x] > A[y] ) {
                // 친구로 만드는데 드는 비용이 적은 쪽으로 결합
                parent[x] = y;
            }
            else {
                parent[y] = x;
            }
        }
    }

    set<int> tops;
    set<int>::iterator iter;
    for(int i=1; i<N+1; i++) {
        int x = find(i);
        iter = tops.find(x);
        if (iter == tops.end()) {
            // 친구 목록에 없을 때
            tops.insert(x);
        }
    }

    int costSum = 0;

    for(iter = tops.begin(); iter != tops.end(); iter++) {
        int cost = A[*iter];
        costSum += cost;
        if ( k < costSum ) {
            cout << "Oh no";
            break;
        }
    }

    if ( costSum <= k ) {
        cout << costSum;
    }
}