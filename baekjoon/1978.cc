#include <iostream>

using namespace std;

int main() {
    int N;
    int maxValue = 0;
    cin >> N;
    int arr[N];
    for(int i=0; i<N; i++) {
        int t;
        cin >> t;
        arr[i] = t;
        maxValue = max(maxValue, t);
    }
    bool isPrime[maxValue+1];
    isPrime[1] = false;
    for(int i=2; i<=maxValue; i++) {
        isPrime[i] = true;
    }
    for(int i=2; i*i<=maxValue; i++) {
        if(isPrime[i]) {
            for(int j=i*i; j<=maxValue; j+=i) {
                isPrime[j] = false;
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<N; i++) {
        if(isPrime[arr[i]]) cnt++;
    }

    cout << cnt;
}