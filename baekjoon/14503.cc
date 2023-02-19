#include <iostream>
#include <queue>

struct Status {
    int x;
    int y;
    int d;
};

using namespace std;
int N, M;
int r, c, d;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int rotate[] = {3, 0, 1, 2};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> r >> c >> d;
    int cnt = 0;
    int arr[N][M];
    bool visited[N][M];
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            int x;
            cin >> x;
            arr[i][j] = x;
            visited[i][j] = false;
        }
    }

    Status status;
    status.x = c; status.y = r; status.d = d;
    while(true) {

        if(!visited[status.y][status.x]) {
            cnt++;
            // 청소 쓱싹
            visited[status.y][status.x] = true;
        }

        bool exist = false;

        for(int i=0; i<4; i++) {
            int nx = status.x + dx[i];
            int ny = status.y + dy[i];
            if(nx>=0 && nx<M && ny>=0 && ny<N && !visited[ny][nx] &&
                arr[ny][nx] == 0) {
                exist = true;
                break;
            }
        }

        if(exist) {
            // 청소되지 않은 빈칸이 있을 때
            status.d = rotate[status.d];
            // 90도 회전
            int nx = status.x + dx[status.d];
            int ny = status.y + dy[status.d];
            if(nx>=0 && nx<M && ny>=0 && ny<N && !visited[ny][nx] &&
                arr[ny][nx] == 0) {
                // 어라 청소되지 않은 빈칸이네
                status.x = nx; status.y = ny;
                // 전진!
            }
        }
        else {
            // 청소되지 않은 빈칸이 없을 때
            int moveX = dx[status.d] == 0 ? 0 : -(dx[status.d]);
            int moveY = dy[status.d] == 0 ? 0 : -(dy[status.d]);
            // 이동 반전
            int nx = status.x + moveX;
            int ny = status.y + moveY;
            if(nx>=0 && nx<M && ny>=0 && ny<N &&
                arr[ny][nx] != 1) {
                // 어라 후진 할 수 있네
                status.x = nx; status.y = ny;
                // 후진!
            }
            else {
                break;
            }
        }
    }

    cout << cnt;
}