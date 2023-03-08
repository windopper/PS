#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> matrix;
int N;
long long B;

vector<vector<int>> operator*(vector<vector<int>>& a, vector<vector<int>>& b) {
    vector<vector<int>> ret(a.size(), vector<int>(a.size(), 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                ret[i][j] += (a[i][k] * b[k][j]);
                ret[i][j] %= 1000;
            }
        }
    }
    return ret;
}

vector<vector<int>> fpow(vector<vector<int>>& v, long long b) {
    if (b == 1) return v;
    vector<vector<int>> ret = fpow(v, b / 2);
    if (b % 2 == 0) {
        return ret * ret;
    } else {
        ret = ret * ret;
        return ret * v;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> B;
    matrix.assign(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    matrix = fpow(matrix, B);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] % 1000 << " ";
        }
        cout << "\n";
    }
}