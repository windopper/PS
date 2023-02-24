#include <bits/stdc++.h>

using namespace std;
int N;
int arr[100000];
int tree[400000];

int init(int s, int e, int idx) {
    if(s == e) {
        return tree[idx] = s;
    }
    int m = (s+e) / 2;
    int l = init(s, m, idx*2);
    int r = init(m+1, e, idx*2+1);
    int tmp = arr[l] < arr[r] ? l : r;
    return tree[idx] = tmp;
}

int find(int s, int e, int idx, int l, int r) {
    if(s > r || e < l) return -1;
    if(s >= l && e <= r) return tree[idx];
    int m = (s + e) / 2;
    int a = find(s, m, idx*2, l, r);
    int b = find(m+1, e, idx*2+1, l, r);
    if(a == -1) return b;
    else if(b == -1) return a;
    else {
        return arr[a] < arr[b] ? a : b;
    }
}

int dac(int start, int end) {
    if(start > end) return 0;
    int idx = find(0, N-1, 1, start, end);
    int result = (end-start+1) * arr[idx];

    int tmp = max(dac(start, idx-1), dac(idx+1, end));
    result = max(result, tmp);
    return result;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    init(0, N-1, 1);
    cout << dac(0, N-1);
}