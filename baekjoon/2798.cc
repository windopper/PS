#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    int ans = 0;
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            for(int k=j+1; k<N; k++) {
                int tmp = arr[i] + arr[j] + arr[k];
                if(tmp > M) continue;
                ans = max(ans, tmp);
            }
        }
    }
    cout << ans;
}