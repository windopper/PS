#include <iostream>

using namespace std;

const long long MAX = 1000000000LL;

int n;
int A[MAX];
int q[100000];

int main() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> A[i];
    int m;
    cin >> m;
    for(int i=0; i<m; i++) cin >> q[i];
    return 0;
}