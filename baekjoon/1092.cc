#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<int> weights(N);
    int maxWeight = 0;
    for(int i=0; i<N; i++) {
        cin >> weights[i];
        maxWeight = max(maxWeight, weights[i]);
    }
    int M;
    cin >> M;
    vector<int> boxes(M);
    int maxBox = 0;
    for(int i=0; i<M; i++) {
        cin >> boxes[i];
        maxBox = max(maxBox, boxes[i]);
    }

    if(maxWeight < maxBox) {
        cout << -1;
        return 0;
    }

    sort(weights.begin(), weights.end(), greater<>());
    sort(boxes.begin(), boxes.end(), greater<>());
    vector<int> visited(M, 0);
    int time = 0;
    int cnt = 0;
    int r = 0;
    while(cnt != M) {
        r = 0;
        for(int weight : weights) {
            while(1) {
                if(r >= boxes.size()) break;
                if(visited[r] == 1) {
                    ++r;
                    continue;
                }
                if(weight >= boxes[r]) {
                    visited[r] = 1;
                    ++r;
                    ++cnt;
                    break;
                }
                else {
                    ++r;
                }
            }
            if(r >= boxes.size()) break;
        }
        ++time;
    }

    cout << time;
}