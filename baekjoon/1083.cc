#include <bits/stdc++.h>

using namespace std;
int arr[51];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    int S;
    cin >> S;
    for(int i=0; i<N; i++) {
        int m = arr[i];
        int mi = i;
        for(int j=i+1; j<N; j++) {
            if(S - (j - i) >= 0) {
                if(m < arr[j]) {
                    m = arr[j];
                    mi = j;
                }
            }
        }
        for(int j=mi; j>i; --j) {
            swap(arr[j], arr[j-1]);
        }
        S -= (mi - i);
        if(S<=0) break;
    }

    for(int i=0; i<N; i++) {
        cout << arr[i] << " ";
    }
}