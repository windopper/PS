#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    int layer = 1;
    long long sum = 1;
    long long acc = 6;
    while(1) {
        if(sum >= N) {
            cout << layer;
            break;
        }
        sum += layer * acc;
        ++layer;
    }
}