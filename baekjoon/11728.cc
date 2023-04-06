#include <bits/stdc++.h>

using namespace std;
int N;
int arr[2000001];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    for(int i=0; i<N+M; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N+M);
    for(int i=0; i<N+M; i++) {
        cout << arr[i] << " ";
    }
}