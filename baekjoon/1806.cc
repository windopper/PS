#include <bits/stdc++.h>

using namespace std;
int N, S;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> S;
    arr.resize(N);
    int sum = 0;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    int left = 0;
    int right = 0;
    int len = 100000;
    int curSum = arr[0];
    bool loop = true;
    if(sum < S) {
        cout << 0;
        loop = false;
    }
    while (loop) {
        if(curSum < S && right >= N-1) {
            break;
        }
        while(curSum < S && right < N-1) {
            curSum += arr[right+1];
            right++;
        }
        while(curSum >= S && left <= right) {
            len = min(len, right - left + 1);
            curSum -= arr[left];
            left++;
        }
    }
    if(loop) cout << len;
}