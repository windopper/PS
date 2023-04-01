#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K;
    cin >> N >> K;

    int a = -1;
    int b = -1;
    bool canCreate = false;
    for(int i=1; i<=N-1; i++) {
        int j = N-i;
        a = i;
        b = j;
        if(a * b >= K) {
            canCreate = true;
            break;
        }
    }

    if(!canCreate) {
        cout << -1;
        return 0;
    }

    int diff = a * b - K;
    // b < diff 이면 diff % b 만큼 마지막 A를 이동
    // b >= diff 이면 diff 만큼 마지막 A를 이동
    int last = b >= diff ? diff : (b % diff);
    // A를 일반적인 순서대로 놓는 개수
    // b < diff 이면 a-(diff / b + 1)만큼 A를 안 움직여도 됨
    // b >= diff 이면 a-1 만큼 A를 안 움직여도 됨
    // diff == 0 이면 0 만큼 A를 안 움직여도 됨
    int full = a - (diff == 0 ? 0 : (diff / b + 1));

    string s = "";
    for(int i=1; i<=N; i++) {
        // A를 놓을 수 있고 남는 A가 있을 때
        if(full >= i) {
            --a;
            s += 'A';
        }
        else {
            // 중간에 집어넣을 A가 없고 A가 남았을 때
            if(last == 0 && a >= 1) {
                --a;
                s += 'A';
            } 
            // 중간에 집어넣을 A가 없고 B가 남았을 때
            else if(last == 0 && b >= 1) {
                --b;
                s += 'B';
            }
            // 중간에 집어넣을 A가 있고 B가 남았을 때
            else if(last > 0 && b >= 1) {
                --b;
                --last;
                s += 'B';
            }
        }
    }
    cout << s;
}