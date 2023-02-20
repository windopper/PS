#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll DIV = 1000000007;

int N;
ll arr[2000001] = {0, };
ll cost[2000001] = {0, };
ll accumulate[2000001] = {0, };
ll tree[8000004] = {0, };

ll init(int start, int end, int index) {
    if(start == end) {
        tree[index] = cost[start];
        return tree[index];
    }
    int mid = (start+end) / 2;
    ll left = init(start, mid, index*2);
    ll right = init(mid+1, end, index*2+1);
    return tree[index] = ((left % DIV) * (right % DIV)) % DIV;
}

int main() {
    cin >> N;
    for(int i=1; i<N+1; i++) {
        cin >> arr[i];
        accumulate[i] = accumulate[i-1] + arr[i];
        cost[i] = abs(accumulate[i] - i * arr[i]);
        if(cost[i] == 0) cost[i] = 1;
    }
    
    init(1, N, 1);
    for(int j=1; j<N+1; j++) {
        cout << accumulate[j] << " ";
    }
    cout << endl;
    for(int j=1; j<N+1; j++) {
        cout << cost[j] << " ";
    }
    cout << endl;
    for(int i=1; i<4*N+1; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;
    cout << tree[1];
}