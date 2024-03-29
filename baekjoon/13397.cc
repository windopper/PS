#include <bits/stdc++.h>
#include <limits>

using namespace std;
int arr[5001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    int maxElement = 0;
    int minElement = 10000;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        maxElement = max(maxElement, arr[i]);
        minElement = min(minElement, arr[i]);
    }

    int s = 0;
    int e = maxElement-minElement;
    int ret = 10000;

    while(s<=e) {
        int mid = (s+e) / 2;
        int maxScore = 0;
        int tMax = arr[0];
        int tMin = arr[0];
        int l = 1;
        for(int i=1; i<N; i++) {
            tMax = max(tMax, arr[i]);
            tMin = min(tMin, arr[i]);
            if((tMax - tMin) > mid) {
                ++l;
                tMax = arr[i];
                tMin = arr[i];
            }
        }
        // 그룹 수가 M보다 크면
        if(l > M) {
            // 기준을 높이자
            s = mid+1;
        }
        else if(l <= M) {
            ret = mid;
            e = mid-1;
        }
    }
    cout << ret;
}