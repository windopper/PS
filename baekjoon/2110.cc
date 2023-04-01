#include <bits/stdc++.h>

using namespace std;
int arr[200001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, C;
    cin >> N >> C;
    int maxElement = 0;
    int minElement = 1000000000;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        maxElement = max(maxElement, arr[i]);
        minElement = min(minElement, arr[i]);
    }
    sort(arr, arr+N);
    int s = 0;
    int e = maxElement;
    int ans = 0;
    while(s<=e) {
        int mid = (s+e)/2;
        int cnt = 0;
        int pivot = minElement;
        cnt = 1;
        for(int i=0; i<N; i++) {
            if(arr[i] - pivot > mid) {
                pivot = arr[i];
                ++cnt;
            }
        }
        
        // 개수가 줄어들면 거리를 줄어야 한다.
        if(cnt < C) {
            e = mid-1;
        }
        else {
            s = mid+1;
        }
    }

    cout << s;
}