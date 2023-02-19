#include <iostream>

typedef long long ll;
using namespace std;
int N, Q;
ll tree[4000004] = {0, };

// 일반적인 세그트리
void update(int start, int end, int index, int updateIdx, int updateData) {
    if(updateIdx < start || updateIdx > end) return;
    tree[index] += updateData;
    if(start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, index*2, updateIdx, updateData);
    update(mid+1, end, index*2+1, updateIdx, updateData);
}

ll query(int start, int end, int index, int left, int right) {
    if(right < start || left > end) return 0;
    if(start >= left && end <= right) {
        return tree[index];
    }
    int mid = (start + end) / 2;
    return query(start, mid, index*2, left, right) + query(mid+1, end, index*2+1, left, right);
}

// 펜윅 트리 풀이
ll sum(int i) {
    ll ans = 0;
    while ( i > 0 ) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

ll sum(int i, int j) {
    return sum(j) - sum(i-1);
}

void update(int i, ll diff) {
    while ( i < 4000004 ) {
        tree[i] += diff;
        i += (i & -i);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    for(int i=0; i<Q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            //update(1, N, 1, b, c);
            update(b, c);
        }
        else {
            //cout << query(1, N, 1, b, c) << "\n";
            cout << sum(b, c) << "\n";
        }
    }
    return 0;
}


