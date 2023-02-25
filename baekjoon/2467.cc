#include <bits/stdc++.h>
#include <limits>

using namespace std;
int N;
vector<int> arr;
int diff = numeric_limits<int>::max();
int a, b = 0;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    arr.resize(N);
    for(int i=0; i<N; i++) cin >> arr[i];
    int left = 0;
    int right = N-1;
    while(left < right) {
        int tmp = arr[left] + arr[right];
        if(tmp == 0) {
            a = arr[left];
            b = arr[right];
            break;
        }
        if(abs(tmp) < diff) {
            diff = abs(tmp);
            a = arr[left];
            b = arr[right];
        }
        if(tmp < 0) {
            ++left;
        }
        else {
            --right;
        }
    }
    if(a < b) swap(a, b);
    cout << b << " " << a;

}