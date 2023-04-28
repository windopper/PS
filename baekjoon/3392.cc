#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int N;
int tree[120004] = {0, };
int cntTree[120004] = {0, };

void update(int s, int e, int i, int l, int r, int ud) {
    if(s > r || e < l) return;
    if(s >= l && e <= r) {
        tree[i] += ud;
    }
    else {
        int m = (s+e)/2;
        update(s, m, i*2, l, r, ud);
        update(m+1, e, i*2+1, l, r, ud);
    }
    
    if(tree[i]) cntTree[i] = e - s + 1;
    else {
        if(s == e) cntTree[i] = 0;
        else cntTree[i] = cntTree[i*2] + cntTree[i*2+1];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    vector<vector<int>> arr;
    for(int i=0; i<N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ++y1; ++y2;
        arr.push_back({x1, y1, y2-1, 1});
        arr.push_back({x2, y1, y2-1, -1});
    }

    sort(arr.begin(), arr.end(), [](vi& a, vi& b) {
        return a[0] < b[0];
    });

    int beforeX = -1;
    long long ret = 0;
    for(int i=0; i<arr.size(); i++) {
        vector<int> cur = arr[i];
        if(beforeX == -1) {
            beforeX = cur[0];
            int y1 = cur[1];
            int y2 = cur[2];
            int ud = cur[3];
            update(1, 30001, 1, y1, y2, ud);
        }
        else {
            int type = cur[3];
            int x1 = cur[0];
            long long yLength = cntTree[1];
            ret += yLength * (x1 - beforeX);
            int y1 = cur[1];
            int y2 = cur[2];
            update(1, 30001, 1, y1, y2, type);
            beforeX = x1;
        }
    }

    cout << ret;
}