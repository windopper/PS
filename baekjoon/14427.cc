#include <bits/stdc++.h>

using namespace std;
int N;
int arr[100001];
int t[400004];
int tmm[400004];

void merge(int i) {
  tmm[i] = min(tmm[i * 2], tmm[i * 2 + 1]);
  if (tmm[i * 2] < tmm[i * 2 + 1])
    t[i] = t[i * 2];
  else if (tmm[i * 2] > tmm[i * 2 + 1])
    t[i] = t[i * 2 + 1];
  else {
    t[i] = min(t[i * 2], t[i * 2 + 1]);
  }
}

void init(int s, int e, int i) {
    if(s == e) {
      tmm[i] = arr[s];
      t[i] = s;
      return;
    }
    int m = (s+e) / 2;
    init(s, m, i*2);
    init(m+1, e, i*2+1);
    merge(i);
}

void update(int s, int e, int i, int ui, int ud) {
    if(s > ui || e < ui) return;
    if(s == e) {
      tmm[i] = ud;
      return;
    }
    int m = (s+e) / 2;
    update(s, m, i*2, ui, ud);
    update(m+1, e, i*2+1, ui, ud);
    merge(i);
}

int query(int s, int e, int i, int l, int r) {
    if(s > r || e < l) return 100000;
    if(s >= l && e <= r) return t[i];
    int m = (s+e) / 2;
    int a = query(s, m+1, i*2, l, r);
    int b = query(m+1, e, i*2+1, l, r);

    if(a == 100000) return b;
    else if(b == 100000) return a;

    if(arr[a] < arr[b]) return a;
    else if(arr[a] > arr[b]) return b;
    else {
        return a < b ? a : b;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i+1];
    init(1, N, 1);
    int M = 0;
    cin >> M;
    for(int i=0; i<M; i++) {
        int c;
        cin >> c;
        if(c == 1) {
            int a, b;
            cin >> a >> b;
            arr[a] = b;
            update(1, N, 1, a, b);
        }
        else {
            cout << query(1, N, 1, 1, N) << '\n';
        }
    }
}