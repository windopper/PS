#include <bits/stdc++.h>

using namespace std;
const int INF = 100002;

int minTree[INF];
int sumTree[INF];

void update(int s, int e, int idx, int updateIdx, int updateData) {
    if (s > idx || e < idx) return;
    if (s == e) {
        minTree[idx] = updateData;
        sumTree[idx] = updateData;
        return;
    }
    int m = (s + e) / 2;
    update(s, m, idx * 2, updateIdx, updateData);
    update(m + 1, e, idx * 2 + 1, updateIdx, updateData);
    minTree[idx] = min(minTree[idx * 2], minTree[idx * 2 + 1]);
    sumTree[idx] = sumTree[idx*2] + sumTree[idx*2+1];
}

int querySum(int s, int e, int idx, int l, int r) {
    if(s > r || e < l) return 0;
    if(s >= l && e <= r) return sumTree[idx];
    int m = (s+e)/2;
    return querySum(s, m, idx*2, l, r) + querySum(m+1, e, idx*2+1, l, r);
}

int queryMin(int s, int e, int idx, int l, int r) {
    if(s > r || e < l) return 1000000;
    if(s >= l && e <= r) return minTree[idx];
    int m = (s+e)/2;
    return queryMin(s, m, idx*2, l, r) + queryMin(m+1, e, idx*2+1, l, r);
}

int solve(int l, int r) {
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int t;
        cin >> t;
        update(1, N, 1, i+1, t);
    }


}