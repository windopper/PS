#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    int arr[100001];
    long long total = 0;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    total *= 2;
}