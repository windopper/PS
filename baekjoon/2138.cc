#include <bits/stdc++.h>

using namespace std;
string cur, target;

void click(int v) {
    for(int i=-1; i<2; i++) {
        if(v+i < 0 || v+i >= target.size()) continue;
        cur[v+i] = cur[v+i] == '0' ? '1' : '0';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    cin >> cur >> target;
    int cnt = 0;
    for(int i=0; i<cur.size(); i++) {
        if(i-1 >= 0 && cur[i-1] != target[i-1]) {
            click(i);
            ++cnt;
        }
        else if(cur[i] != target[i]) {
            if(i-1 >= 0) {
                cout << -1;
                return 0;
            }
            click(i);
            ++cnt;
        }
        else if(i + 1 < N && cur[i+1] != target[i+1]) {
            click(i);
            ++cnt;
        }

    }

    cout << cnt;
}