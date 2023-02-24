#include <bits/stdc++.h>
#include <ios>

using namespace std;
vector<int> arr;
int N, S;
bool visited[20] = {false, };
int solve(vector<int>& path, int sum, int idx) {
    //cout << sum << " ";
    if(sum == S && path.size() > 0) return 1;
    if(idx+1 >= arr.size()) return 0;
    int res = 0;
    for(int i=idx+1; i<arr.size(); i++) {
        visited[i] = true;
        path.push_back(arr[i]);
        res += solve(path, sum + arr[i], i);
        path.pop_back();
        visited[i] = false;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> S;
    arr.resize(N);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<int> path;
    cout << solve(path, 0, -1);
}