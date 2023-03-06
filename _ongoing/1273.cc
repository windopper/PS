#include <bits/stdc++.h>

using namespace std;
const int MOD = 3000000;
int p[3] = {1, 2, 5};
int N, M;

int heightTree[MOD] = {
    0,
};
int sum[MOD];
int cnt[MOD + 1];

void heightUpdate(int i) {
    while (i < MOD) {
        heightTree[i] += 1;
        i += (i & -i);
    }
}

int heightQuery(int i) {
    int ret = 0;
    while (i > 0) {
        ret += heightTree[i];
        i -= (i & -i);
    }
    return ret;
}

int heightQuery(int i, int j) { return heightQuery(j) - heightQuery(i - 1); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            sum[cnt[j]] += p[i];
            sum[cnt[j] + temp] -= p[i];
            cnt[j] += temp;
        }
    }

    for (int i = 0; i < MOD; i++) {
        if (i != 0) sum[i] += sum[i - 1];
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        int nextHeight = heightQuery(1, a) + a;
        cout << sum[nextHeight - 1] << "\n";
        heightUpdate(a);
    }
}
