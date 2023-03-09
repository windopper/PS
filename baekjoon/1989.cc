#include <bits/stdc++.h>

using namespace std;
const int INF = 100002;

int minTree[INF];

void update(int s, int e, int idx, int updateIdx, int updateData) {
    if (s > idx || e < idx) return;
    if (s == e) {
        minTree[idx] = updateData;
        return;
    }
    int m = (s + e) / 2;
    update(s, m, idx * 2, updateIdx, updateData);
    update(m + 1, e, idx * 2 + 1, updateIdx, updateData);
    minTree[idx] = min(minTree[idx * 2], minTree[idx * 2 + 1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
}