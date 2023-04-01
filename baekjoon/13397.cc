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
    int e = maxElement - minElement;
    int ret = 10000;

    while(s<=e) {
        int mid = (s+e) / 2;
        int maxScore = 0;
        int tMax = arr[0];
        int tMin = arr[0];
        int l = 1;
        int element = 1;
        for(int i=1; i<N; i++) {
            if(arr[i] - tMin > mid || tMax - arr[i] > mid) {
                maxScore = max(maxScore, tMax-tMin);
                tMax = 0;
                tMin = 0;
                element = 0;
            }
            if(element == 0) ++l;
            ++element;
            tMax = max(tMax, arr[i]);
            tMin = min(tMin, arr[i]);
        }
        // 그룹 수가 M보다 크면
            cout << maxScore << " " << l << " " << s << " " << e << " " << "\n";
        if(l >= M) {
            // 기준을 높이자
            ret = maxScore;
            s = mid+1;
        }
        else if(l <= M) {
            e = mid-1;
        }
    }
    cout << ret;
}