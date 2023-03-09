#include <bits/stdc++.h>

using namespace std;
int MAXLEVEL;
int sparseTable[18][100001];
// 희소배열은 logn 탐색을 위해 1, 2, 4, 8 만큼 이동했을 때의 노드를 저장한다.
// spraseTable[k][x] x번 노드에서 2^k만큼 떨어진 노드
int level[100001];
int N;

// 희소 배열 초기화
void dfs(int node, vector<vector<int>>& arr) {
    for (int i = 0; i < arr[node].size(); i++) {
        int nextNode = arr[node][i];
        if (level[nextNode] != -1) continue;
        level[nextNode] = level[node] + 1;
        sparseTable[0][nextNode] = node;
        // node에서 1번 이동하여 parentNode로 갈 수 있다는 뜻
        dfs(nextNode, arr);
    }
}

int solve(int a, int b) {
    // a. b중 level이 더 높은 노드에 대해 노드의 level이 같아지도록 조정한다.
    if (level[a] < level[b]) swap(a, b);
    int levelDiff = level[a] - level[b];
    for (int i = 0; levelDiff != 0; i++) {
        if (levelDiff % 2 == 1) a = sparseTable[i][a];
        levelDiff /= 2;
        // 레벨 차이가 2의 배수일 경우에는 sparseTable에서 즉시 이동가능하므로 이동하자
        // ex)
        // levelDiff가 5이면 이진수로 변환하였을 때 101 이므로
        // 첫번째와 세번째 비트에서 a가 2^i번 씩 이동한 것과 같다.
        // 이는 기존의 a에서 5번 이동한 것과 같다.
    }

    // level을 맞췄으면 최소 공통 조상을 구한다.
    int ret = a;

    // 기저조건: level이 같아지도록 조정하였을 때 이미 같다면 해당 노드가 공통조상이다.
    if (a != b) {
        // 레벨 17, 16, ..., 1 순으로 시도하면서 가장 레벨이 높은 공통 조상을 찾는다.
        for (int i = MAXLEVEL - 1; i >= 0; --i) {
            if (sparseTable[i][a] != 0 && sparseTable[i][a] != sparseTable[i][b]) {
                a = sparseTable[i][a];
                b = sparseTable[i][b];
            }
        }
        ret = sparseTable[0][a];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (; T > 0; --T) {
        cin >> N;
        MAXLEVEL = (int)ceil(log2(N)) + 1;
        vector<vector<int>> arr(N + 1);
        fill_n(level, N + 1, 0);

        for (int i = 0; i < N - 1; i++) {
            int a, b;
            cin >> a >> b;
            arr[a].push_back(b);
            ++level[b];
        }

        int root = -1;
        for (int i = 1; i < N + 1; i++) {
            if (level[i] == 0) {
                root = i;
                break;
            }
        }

        fill_n(level, N + 1, -1);
        level[root] = 0;

        dfs(root, arr);

        for (int i = 1; i < MAXLEVEL; ++i) {
            for (int j = 1; j < N + 1; ++j) {
                sparseTable[i][j] = sparseTable[i - 1][sparseTable[i - 1][j]];
                // ex)
                // sparseTable[1][3] = spraseTable[0][sparseTable[0][3]];
                // 3번 노드에서 2^1번 이동하여 갈 수 있는 노드는
                // 3번 노드에서 2^0번 이동하여 간 노드에서 2^0번 더 이동해서 갈 수 있는 노드이다.
                // 즉, 2^1 = 2^0 + 2^0
            }
        }

        int c, d;
        cin >> c >> d;
        cout << solve(c, d) << "\n";
    }
}