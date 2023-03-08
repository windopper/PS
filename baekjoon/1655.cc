#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;

    priority_queue<int> sq;
    priority_queue<int, vector<int>, greater<>> bq;
    // 주의점
    // - 오른쪽 힙이 왼쪽 힙보다 크기가 커질 수 없다.
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (sq.empty() && bq.empty()) {
            sq.push(temp);
        } else if (!sq.empty() && bq.empty()) {
            if (sq.top() >= temp) {
                bq.push(sq.top());
                sq.pop();
                sq.push(temp);
                // 교체
            } else {
                bq.push(temp);
            }
        } else if (sq.top() <= temp && bq.top() >= temp) {
            // 오른쪽 힙과 왼쪽 힙 최소 최대 값 사이에 있다면 끼워넣어야 한다.
            if (sq.size() - bq.size() == 1) {
                // 왼쪽 힙이 크기가 더 크다면 오른쪽에 넣어도 된다.
                bq.push(temp);
            } else {
                sq.push(temp);
            }

        } else if (bq.top() < temp) {
            // 오른쪽 힙의 최대값이 현재 값보다 작다면
            // 그 값이 오른쪽 힙으로 들어가야 한다.
            if (bq.size() - sq.size() == 0) {
                sq.push(bq.top());
                bq.pop();
            }
            bq.push(temp);
        } else if (sq.top() > temp) {
            // 왼쪽 힙의 최대값이 현재 값보다 크다면
            // 그 값이 왼쪽힙으로 들어가야 한다.
            if (sq.size() - bq.size() == 1) {
                // 왼쪽 힙이 오른쪽 힙으로 들어갈 때 크기 차이가 1이라면
                // 값이 들어갈 때 오른쪽 힙보다 2개더 많아지므로
                // 개수를 맞춰주기 위해 왼쪽 힙의 최대값을 오른쪽 힙으로 던져 준다.
                bq.push(sq.top());
                sq.pop();
            }
            sq.push(temp);
        }

        cout << sq.top() << "\n";
    }
}