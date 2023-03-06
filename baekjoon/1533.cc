#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MOD = 1000003;
ll N, S, E, T;
vector<vector<ll>> arr;

// 행렬 곱셈 구현
vector<vector<ll>> operator*(vector<vector<ll>>& v1, vector<vector<ll>>& v2) {
    vector<vector<ll>> ret(5 * N, vector<ll>(5 * N));
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            for (int k = 0; k < v1.size(); k++) {
                ret[i][j] += v1[i][k] * v2[k][j];
                // (i, j) = (i, k) X (k, j)
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

// 분할정복을 이용한 거듭제곱
vector<vector<ll>> fpow(vector<vector<ll>>& v, int n) {
    if (n == 1) {
        return v;
    } else {
        vector<vector<ll>> ret = fpow(v, n / 2);
        if (n % 2 == 0) {
            return ret * ret;
        } else {
            vector<vector<ll>> tmp = ret * ret;
            return tmp * v;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 문제의 핵심은 가중치가 있는 그래프를 가중치가 없는 그래프로 변형하는 것
    // 예를들어 가중치가 5인 경로가 있다면 가중치가 1인 그래프 5개로 쪼개서 하면 된다.
    // 여기서 가중치가 1이라는 것은 정점이 연결되어 있다는 뜻
    // 무방향 그래프의 인접행렬이 만들어 졌으면 인접행렬에 대하여 n승을 하여 경로의 개수를 구할 수 있다.
    // 여기서 n이란 문제에서 주어지는 T와 같다.

    cin >> N >> S >> E >> T;
    arr.resize(5 * N, vector<ll>(5 * N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char a;
            cin >> a;
            int t = atoi(&a);
            if (t > 0) {
                arr[i * 5][j * 5 + t - 1] = 1;
                for (int k = 1; k < t; k++) {
                    arr[5 * j + k][5 * j + k - 1] = 1;
                }
            }
        }
    }

    cout << fpow(arr, T)[5 * (S - 1)][5 * (E - 1)];
}