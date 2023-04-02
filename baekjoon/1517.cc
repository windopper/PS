#include <bits/stdc++.h>

using namespace std;
int arr[500001];
int maxTree[2000000];
int cntTree[2000000];

void init(int s, int e, int i) {
    if (s == e) {
        maxTree[i] = arr[s];
        cntTree[i] = 0;
        return;
    }
    int m = (s + e) / 2;
    init(s, m, i * 2);
    init(m + 1, e, i * 2 + 1);
    maxTree[i] = max(maxTree[i * 2], maxTree[i * 2 + 1]);
    cntTree[i] = cntTree[i * 2] + cntTree[i * 2 + 1];
    if (maxTree[i * 2] > maxTree[i * 2 + 1]) {
        cntTree[i] += 1;
    }
    cout << s << " " << e << " " << cntTree[i] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    init(1, N, 1);
    cout << cntTree[1];
}