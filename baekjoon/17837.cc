#include <bits/stdc++.h>

using namespace std;
struct Node;

vector<vector<int>> arr;
vector<Node> nodes;
vector<vector<vector<Node>>> matrix;
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
            this->bottom = nullptr;
        }
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
            return top->getTop();
        }   
        else
            return this;
    }

    void reverse() {
        Node* temp = this->bottom;
        if(this->top != nullptr) this->top->reverse();
        this->bottom = this->top;
        this->top = temp;
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

int main() {
    vector<Node> test;
    Node* cur = new Node(0, 0, 0, 0);
    Node* pre = nullptr;
    for (int i = 0; i < 4; i++) {
        test.push_back(*cur);
        cur->bottom = pre;
        Node nxt = Node(i+1, 0, 0, 0);
        if (i == 3) {
            cur->top = nullptr;
        } else {
            cur->top = &nxt;
        }
        pre = cur;
        cur = &nxt;
    }

    cur = &test[0];
    while(cur->top != nullptr) {
        cout << cur->n << " ";
        cur = cur->top;
    }
    cur = &test[0];
    //cout << cur->n << cur->top << " ";
    cur->reverse();
    Node* top = cur->getTop();
    top->bottom = nullptr;
    cur->top = nullptr;
    cur = &test[3];
    //cout << cur->n << cur->top << " ";

    while(cur->top != nullptr) {
        cout << cur->n << " ";
        cur = cur->top;
    }
    
    return 0;

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
        nodes.push_back(Node(i, b, a, c));
    }

    int turn = 0;
    while (1) {
        for (int i = 0; i < K; i++) {
            if (turn > 1000) {
                cout << -1;
                return 0;
            }
            int x = nodes[i].x;
            int y = nodes[i].y;
            int dir = nodes[i].dir;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            // blue or outside
            if (isOutOfRange(nx, ny)) {
                int opdir = opposite(dir);
                int rnx = x + dx[opdir];
                int rny = y + dy[opdir];
                nodes[i].dir = opdir;
                if (isOutOfRange(rnx, rny)) continue;
                if (arr[rny][rnx] == 2) continue;
                nodes[i].move(rnx, rny);
                continue;
            } else if (arr[ny][nx] == 2) {
                int opdir = opposite(dir);
                int rnx = x + dx[opdir];
                int rny = y + dy[opdir];
                nodes[i].dir = opdir;
                if (isOutOfRange(rnx, rny)) continue;
                if (arr[rny][rnx] == 2) continue;
                nodes[i].move(rnx, rny);
                continue;
            }
            // red
            else if (arr[ny][nx] == 1) {
                // 원래 있던 자리에 있는 노드를 구한다
                Node* bot = nullptr;
                for (int j = 0; j < K; j++) {
                    Node nxt = nodes[j];
                    if (nxt.x == nx && nxt.y == ny) {
                        bot = nxt.getTop();
                        break;
                    }
                }
                // 이전에 있던 노드들을 옮기기
                nodes[i].move(nx, ny);
                // 이전에 있던 노드들의 제일 꼭대기에 있는 놈 구하기
                Node* top = nodes[i].getTop();
                // 반대로 돌리기, 그러면 꼭대기에 있는 놈은 아래로 옴
                nodes[i].reverse();
                
                //nodes[i].top = -1;

                if (bot != nullptr) {
                    //nodes[bot].top = top;
                }
                //nodes[top].bottom = bot;
            }
            // white
            else if (arr[ny][nx] == 0) {
                Node* bot = nullptr;
                for (int j = 0; j < K; j++) {
                    Node nxt = nodes[j];
                    if (nxt.x == nx && nxt.y == ny) {
                        bot = nxt.getTop();
                        break;
                    }
                }
                nodes[i].move(nx, ny);
                if (bot != nullptr) {
                    //nodes[i].bottom = bot;
                    //nodes[bot].top = i;
                }
            }
            ++turn;
        }
    }

    cout << turn;
}