#include <bits/stdc++.h>

using namespace std;

vector<int> s3[8] = {
    {0, 1, 2}, {0, 2, 4}, {0, 3, 4}, {0, 1, 3},
    {5, 1, 3}, {5, 3, 4}, {5, 4, 2}, {5, 1, 2}
};

vector<int> s2[12] = {
    {0, 1}, {0, 2}, {0, 4}, {0, 3},
    {1, 3}, {3, 4}, {2, 4}, {1, 2},
    {5, 1}, {5, 3}, {5, 4}, {5, 2},
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long N;
    cin >> N;
    vector<int> arr(6);
    int maxS1 = 0;
    int minS1 = 1000000;
    int total = 0;
    for(int i=0; i<6; i++) {
        cin >> arr[i];
        maxS1 = max(maxS1, arr[i]);
        minS1 = min(minS1, arr[i]);
        total += arr[i];
    }

    int minS3 = numeric_limits<int>::max();
    for(int i=0; i<8; i++) {
        int t = 0;
        for(int l : s3[i]) {
            t += arr[l];
        }
        minS3 = min(minS3, t);
    }

    int minS2 = numeric_limits<int>::max();
    for(int i=0; i<12; i++) {
        int t = 0;
        for(int l : s2[i]) {
            t += arr[l];
        }
        minS2 = min(minS2, t);
    }
    
    if(N==1) {
        cout << total - maxS1;
    }
    else if(N==2) {
        cout << minS3 * 4 + minS2 * 4;
    }
    else {
        long long remain = N - 2;
        long long ans = 0;
        ans += remain * remain * 5 * minS1 + remain * 4 * minS1;
        ans += remain * 8 * minS2 + 4 * minS2;
        ans += 4 * minS3;
        cout << ans;
    }
}