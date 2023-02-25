#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    deque<int> q;
    for(int i=1; i<n+1; i++) {
        q.push_back(i);
    }
    while(q.size() > 1) {
        q.pop_front();
        q.push_back(q.front());
        q.pop_front();
    }
    cout << q.front();
}