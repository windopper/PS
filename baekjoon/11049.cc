#include <bits/stdc++.h>
#include <ios>

using namespace std;
int N;
vector<pair<int, int>> arr;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        int r, c;
        cin >> r >> c;
        arr.push_back({r, c});
    }
}