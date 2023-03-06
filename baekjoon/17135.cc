#include <bits/stdc++.h>

using namespace std;
int N, M, D;
vector<vector<int>> arr;
int answer = 0;

int getDist(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

bool isEnemyRemain(vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1) return true;
        }
    }
    return false;
}

int attackEnemy(vector<pair<int, int>>& archer, vector<vector<int>>& board) {
    vector<pair<int, int>> removeList;
    int attackCnt = 0;
    for (int k = 0; k < 3; k++) {
        int nearestX = 15;
        int nearestY = 15;
        int distance = D;
        int x = archer[k].first;
        int y = archer[k].second;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] != 1) continue;
                int dist = getDist(x, y, j, i);
                if (distance == dist && nearestX > j) {
                    nearestX = j;
                    nearestY = i;
                } else if (distance > dist) {
                    distance = dist;
                    nearestX = j;
                    nearestY = i;
                }
            }
        }
        if (nearestX != 15) {
            removeList.push_back({nearestX, nearestY});
        }
    }
    for (pair<int, int> remove : removeList) {
        if (board[remove.second][remove.first] == 1) {
            ++attackCnt;
            board[remove.second][remove.first] = 0;
        }
    }
    return attackCnt;
}

vector<vector<int>> moveEnemy(vector<vector<int>>& board) {
    vector<vector<int>> newBoard(N + 1, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        if (i == N - 1) continue;
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1) {
                newBoard[i + 1][j] = 1;
            }
        }
    }
    return newBoard;
}

int simulate(vector<pair<int, int>>& archer) {
    vector<vector<int>> board = arr;
    int ret = 0;
    while (isEnemyRemain(board)) {
        ret += attackEnemy(archer, board);
        board = moveEnemy(board);
    }
    return ret;
}

void setArcher(vector<pair<int, int>>& archer, int a) {
    if (archer.size() == 3) {
        answer = max(answer, simulate(archer));
        return;
    }
    for (int i = a + 1; i < M; i++) {
        archer.push_back({i, N});
        setArcher(archer, i);
        archer.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> D;
    for (int i = 0; i < N; i++) {
        vector<int> vec;
        for (int j = 0; j < M; j++) {
            int temp = 0;
            cin >> temp;
            vec.push_back(temp);
        }
        arr.push_back(vec);
    }
    vector<int> vec;
    for (int i = 0; i < M; i++) {
        vec.push_back(0);
    }
    arr.push_back(vec);

    vector<pair<int, int>> archer;
    setArcher(archer, -1);
    cout << answer;
}