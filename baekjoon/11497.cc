#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(; T>0; --T) {
        int N; cin >> N;
        vector<int> arr;
        for(int i=0; i<N; i++) {
            int L; cin >> L;
            arr.push_back(L);
        }
        sort(arr.begin(), arr.end());
        vector<int> result(N);
        int idx = 0;
        int r = 0;
        int l = N-1;
        while(1) {
            if(idx < arr.size()) {
                result[r] = arr[idx];
                ++idx;
                ++r;
            }
            else break;
            if(idx < arr.size()) {
                result[l] = arr[idx];
                ++idx;
                --l;
            }
            else break;
        }
        int diff = abs(result[0] - result.back());
        for(int i=0; i<result.size()-1; i++) {
            diff = max(diff, abs(result[i] - result[i+1]));
        }

        cout << diff << "\n";
    }
}