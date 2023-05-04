#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>>& sizes, int cur, int w, int h) {
    if(cur == sizes.size()) {
        return w * h;
    }
    int ret = 987654321;
    ret = min(ret, solve(sizes, cur + 1, max(w, sizes[cur][0]), max(h, sizes[cur][1])));
    
    ret = min(ret, solve(sizes, cur + 1, max(w, sizes[cur][1]), max(h, sizes[cur][0])));
    return ret;
}

int solution(vector<vector<int>> sizes) {
    return solve(sizes, 0, 0, 0);
}