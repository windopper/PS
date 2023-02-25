#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<int> heights;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    heights.resize(N);
    for(int i=0; i<N; i++) cin >> heights[i];
    
    int maxValue = 0;
    for(int i=0; i<N; i++) maxValue = max(maxValue, heights[i]);
    int left = 0; int right = maxValue;
    int mid = (left + right) / 2;
    int res = 0;
    while(left <= right) {
        mid = (left + right) / 2;
        long long take = 0;
        for(int i=0; i<N; i++) {
            if(heights[i] > mid) take += heights[i] - mid;
        }
        if(take >= M) {
            // 가져간 나무가 필요한 나무보다 더 많거나 같을 때
            res = mid;
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }
    cout << res;
}