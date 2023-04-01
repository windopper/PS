#include <bits/stdc++.h>
#include <limits>

using namespace std;
int arr[100001];
int N, M;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    long long total = 0;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    long long target = *max_element(arr, arr+N);
    int s = target;
    int e = total;
    long long ans = N;
    while (s <= e) {
        long long m = (s + e) / 2;
        long long l = 0;
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            if (sum + arr[i] > m) {
                sum = 0;
            }
            if (sum == 0) ++l;
            sum += arr[i];
        }

        // 블루레이의 개수가 원하는 값보다 크다면
        // 더 용량을 늘려야 함
        if (l > M) {
            s = m+1;
        }
        else if(l <= M) {
            ans = m;
            e = m-1;
        }
    }

    cout << ans;
}