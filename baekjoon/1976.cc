#include <iostream>
#include <vector>

using namespace std;
int N, M;
int parent[205];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    cin >> M;

    for(int i=0; i<N+1; i++) {
        parent[i] = i;
    }

    for(int i=1; i<N+1; i++) {
        int tmp;
        for(int j=1; j<N+1; j++) {
            cin >> tmp;
            if (tmp == 1) {
                int a = find(i);
                int b = find(j);
                if ( a != b) {
                    if ( a < b ) parent[b] = a;
                    // 공통 조상을 만들어 주기 위해 
                    // rank 벡터를 따로 만들어 주는 대신
                    // 도시 번호의 크기를 비교함.
                    else parent[a] = b;
                }
            }
        }
    }

    int plan[M+1];
    for(int i=0; i<M; i++) {
        cin >> plan[i];
    }

    bool possible = true;
    int cur = parent[plan[0]];
    for(int i=1; i<M; i++) {
        if ( cur != parent[plan[i]] ) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
    return 0;
}