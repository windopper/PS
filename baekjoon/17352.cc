#include <bits/stdc++.h>

using namespace std;
int N;
int parent[300001] = {0, };

int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1; i<N+1; i++) {
        parent[i] = i;
    }
    for(int i=0; i<N-2; i++) {
        int a, b;
        cin >> a >> b;
        a = find(a);
        b = find(b);
        if(a != b) {
            if(a < b) {
                parent[b] = a;
            }
            else parent[a] = b;
        }
    }
    int a = 0, b = 0;
    for(int i=1; i<N+1; i++) {
        int x = find(i);
        if(a == 0) {
            a = x;
        }
        else if(b == 0 && a != x) {
            b = x;
            break;
        }
    }
    
    cout << a << " " << b;

}