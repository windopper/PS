#include <bits/stdc++.h>

using namespace std;
map<string, int> mi;
map<int, string> ms;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i=1; i<N+1; i++) {
        string s;
        cin >> s;
        mi[s] = i;
        ms[i] = s;
    }

    for(int i=0; i<M; i++) {
        string s;
        cin >> s;
        if(mi[s]) cout << mi[s];
        else cout << ms[stoi(s)];
        cout << '\n';
    }
}