#include <bits/stdc++.h>

using namespace std;
int N, K, B;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K >> B;
    arr.resize(B);
    for(int i=0; i<B; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int left = -1;
    int right = 0;
    int start = 0;
    int end = 0;
    int ans = 100000;
    while(true) {

        if(end - start - 1 >= K) {
            ans = min(ans, right - left - 1);
            ++left;
            if(left >= B) break;
            start = arr[left];
            right = left + 1;
            if(right >= B) end = N+1;
            else end = arr[right];
            continue;
        }
        else {
            if(right >= B) {
                ++left;
                if(left >= B) break;
                start = arr[left];
                right = left + 1;
                if(right >= B) end = N+1;
                else end = arr[right];
                continue;
            }
            else if(left >= B) {
                break;
            }
        }

        ++right;
        if(right >= B) end = N+1;
        else end = arr[right];
    } 

    cout << ans;
}