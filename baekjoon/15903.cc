#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int n, m;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        q.push(a);
    }

    while(m != 0) {
        long long i = q.top(); 
        q.pop();
        long long j = q.top();
        q.pop();
        long long temp = (long long)i + j;
        q.push(temp); 
        q.push(temp);
        m--;
    }

    long long total = 0;
    while(!q.empty()) {
        total += q.top();
        q.pop();
    }
    cout << total;
}