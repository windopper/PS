#include <bits/stdc++.h>

using namespace std;
struct Node;

vector<vector<int>> arr;
vector<Node*> nodes;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, K;

struct Node {
    int n;
    int x;
    int y;
    int dir;
    Node* top = nullptr;
    Node* bottom = nullptr;
    Node(int _n, int _x, int _y, int _dir) : n(_n), x(_x), y(_y), dir(_dir) {}
    Node() {}
    void move(int x, int y) {
        this->x = x;
        this->y = y;
        if (this->top != nullptr) {
            top->moveAdj(x, y);
        }
        if (this->bottom != nullptr) {
            this->bottom->top = nullptr;
        }
        this->bottom = nullptr;
    }

    void moveAdj(int x, int y) {
        this->x = x;
        this->y = y;
        if (this->top != nullptr) {
            top->moveAdj(x, y);
        }
    }

    Node* getTop() {
        if (this->top != nullptr) {
            return this->top->getTop();
        } else
            return this;
    }

    void reverse() {
        if (this->top != nullptr) this->top->reverse();
        swap(this->bottom, this->top);
    }
};

bool isOutOfRange(int x, int y) { return x < 0 || x >= N || y < 0 || y >= N; }

int opposite(int x) {
    if (x == 0) return 1;
    if (x == 1) return 0;
    if (x == 2) return 3;
    if (x == 3) return 2;
    return -1;
}

void moveAndStack(int i, int nx, int ny) {
    Node* bot = nullptr;
    Node* cur = nodes[i];
    for (int j = 0; j < K; j++) {
        Node* nxt = nodes[j];
        if (nxt->x == nx && nxt->y == ny) {
            bot = nxt->getTop();
            break;
        }
    }
    cur->move(nx, ny);
    if (bot != nullptr) {
        cur->bottom = bot;
        bot->top = cur;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    arr.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        --c;
        nodes.push_back(new Node(i, b, a, c));
    }

    int turn = 1;
    while (1) {
        for (int i = 0; i < K; i++) {
            Node* cur = nodes[i];
            Node* check = cur;
            int cnt = 0;

            if (turn > 1000) {
                cout << -1;
                return 0;
            }

            int x = cur->x;
            int y = cur->y;
            int dir = cur->dir;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            // blue or outside
            if (isOutOfRange(nx, ny)) {
                int opdir = opposite(dir);
                int rnx = x + dx[opdir];
                int rny = y + dy[opdir];
                cur->dir = opdir;
                if (isOutOfRange(rnx, rny)) continue;
                if (arr[rny][rnx] == 2) continue;
                // red
                if (arr[rny][rnx] == 1) {
                    Node* top = cur->getTop();
                    Node* bottom = cur->bottom;
                    cur->reverse();
                    cur->top = nullptr;
                    top->bottom = bottom;
                    moveAndStack(top->n, rnx, rny);
                }
                // white
                else if (arr[rny][rnx] == 0) {
                    moveAndStack(i, rnx, rny);
                }
            } else if (arr[ny][nx] == 2) {
                int opdir = opposite(dir);
                int rnx = x + dx[opdir];
                int rny = y + dy[opdir];
                cur->dir = opdir;
                if (isOutOfRange(rnx, rny)) continue;
                if (arr[rny][rnx] == 2) continue;
                //red
                if (arr[rny][rnx] == 1) {
                    Node* top = cur->getTop();
                    Node* bottom = cur->bottom;
                    cur->reverse();
                    cur->top = nullptr;
                    top->bottom = bottom;
                    moveAndStack(top->n, rnx, rny);
                }
                // white
                else if (arr[rny][rnx] == 0) {
                    moveAndStack(i, rnx, rny);
                }
            }
            // red
            else if (arr[ny][nx] == 1) {
                Node* top = cur->getTop();
                Node* bottom = cur->bottom;
                cur->reverse();
                cur->top = nullptr;
                top->bottom = bottom;
                moveAndStack(top->n, nx, ny);
            }
            // white
            else if (arr[ny][nx] == 0) {
                moveAndStack(i, nx, ny);
            }

            Node* checkBot = check;
            while (checkBot->bottom != nullptr) {
                checkBot = checkBot->bottom;
            }
            while (checkBot != nullptr) {
                ++cnt;
                checkBot = checkBot->top;
            }

            if (cnt >= 4) {
                cout << turn;
                return 0;
            }
        }
        ++turn;
    }

    cout << turn;
}