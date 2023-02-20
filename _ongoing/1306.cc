#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    arr.resize(N);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
}