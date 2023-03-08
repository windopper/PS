#include <bits/stdc++.h>

using namespace std;
const int INF = 2000002;
int tree[INF * 4 + 4];

void update(int s, int e, int idx, int updateIdx, int updateData) {
    if (s > updateIdx || e < updateIdx) return;
    if (s == e) {
        tree[idx] += updateData;
        return;
    }
    int m = (s + e) / 2;
    update(s, m, idx * 2, updateIdx, updateData);
    update(m + 1, e, idx * 2 + 1, updateIdx, updateData);
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int find(int s, int e, int idx, int target) {
    if (s == e) return s;
    int mid = (s + e) / 2;
    int left = tree[idx * 2];
    if (target > left) {
        // 왼쪽 트리 개수가 찾고자 하는 k번째에 없다면 오른쪽으로 가자
        return find(mid + 1, e, idx * 2 + 1, target - left);
    }
    return find(s, mid, idx * 2, target);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int T, X;
        cin >> T >> X;
        if (T == 1) {
            update(1, INF, 1, X, 1);
        } else {
            int target = find(1, INF, 1, X);
            cout << target << "\n";
            update(1, INF, 1, target, -1);
        }
    }
}