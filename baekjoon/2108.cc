#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
int N;
vector<int> arr;
vector<int> most;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    arr.resize(N);
    most.resize(8000);
    for(int i=0; i<8000; i++) most[i] = 0;
    int sum = 0;
    int mid = N / 2;
    int cnt = 1;
    int l = -4000;
    int r = 4000;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        sum += arr[i];
        l = max(l, arr[i]);
        r = min(r, arr[i]);
        most[arr[i]+4000] += 1;
    }
    sort(arr.begin(), arr.end());
    double avg = (double)sum / N;

    cout << round(avg)+numeric_limits<int>::epsilon() << "\n";
    cout << arr[mid] << "\n";
    
    for(int i=0; i<N; i++) {
        cnt = max(cnt, most[arr[i]+4000]);
    }
    int idx = 0;
    int ans = -4001;
    for(int i=0; i<N; i++) {
        if(most[arr[i]+4000] == cnt && ans != arr[i]) {
            ++idx;
            ans = arr[i];
            if(idx == 2) {
                break;
            }
        }
    }
    cout << ans << "\n";

    cout << l - r << "\n";

}