#include <bits/stdc++.h>

using namespace std;
int N, K;
vector<int> arr;
vector<int> nums;

int permutation(int cnt, int flag, int r) {
    if(r == cnt) {
        string s;
        for(int i=0; i<r; i++) {
            
        }
        
        return 1;
    }
    int res = 0;
    for(int i=0; i<N; i++) {
        if((flag & 1 << i) != 0) continue;
        // 비트가 선택되었다면 넘어갈까?
        nums[cnt] = arr[i];
        res += permutation(cnt+1, flag | 1 << i, r);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    nums.resize(N);
    for(int i=0; i<N; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    int res = 0;
    for(int i=N; i>0; i--) {
       res += permutation(0, 0, i);
    }
}