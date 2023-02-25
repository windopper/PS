#include <bits/stdc++.h>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(; T>0; T--) {
        int N, M;
        queue<int> q;
        priority_queue<int> pq;
        cin >> N >> M;
 
        for(int i=0; i<N; i++) {
            int tmp;
            cin >> tmp;
            q.push(tmp);
            pq.push(tmp);
        }

        int cnt = 0;
        while(!q.empty()) {
            if(q.front() == pq.top()) {
                //cout << pq.top() << "\n";
                q.pop(); pq.pop();
                cnt++;
                if(M == 0) {
                    cout << cnt << "\n";
                    break;
                }
                --M;
            }
            else {
                q.push(q.front());
                q.pop();
                if(M == 0) M = q.size() - 1;
                else --M;
            }
        }
    }
}