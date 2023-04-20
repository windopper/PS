#include <bits/stdc++.h>

using namespace std;
int N, M;
set<int> arr;

void solve(vector<int>& vec) {
    if(vec.size() == M) {
        for(int i : vec) cout << i << " ";
        cout << '\n';
        return;
    }

    for(set<int>::iterator cur=arr.begin(); cur!=arr.end(); ++cur) {
        vec.push_back(*cur);
        solve(vec);
        vec.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    while(N--) {
        int t;
        cin >> t;
        arr.insert(t);
    }    
    vector<int> vec;
    solve(vec);
}