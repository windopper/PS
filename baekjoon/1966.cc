#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(; T>0; T--) {
        int N, M, maxValue = 0;
        queue<int> q;
        cin >> N >> M;
        for(int i=0; i<N; i++) {
            int tmp;
            cin >> tmp;
            q.push(tmp);
            maxValue = max(tmp, maxValue);
        }
        int cnt = 0;
        while(true) {
            cnt++;
            if(M == q.front()) {
                break;
            }
            else if(maxValue != q.front()) {
                q.push(q.front());
                q.pop();
            }
            else {
                q.pop();
                for(int i=0; i<q.size(); i++) {
                    maxValue = max(maxValue, q.front());
                    q.push(q.front());
                    q.pop();
                }
            }
        }
        cout << cnt << "\n";
    }
}