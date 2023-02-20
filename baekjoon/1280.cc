#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll DIV = 1000000007;

int N;
ll arr[2000001] = {0, };
ll cost[2000001] = {0, };
ll tree[8000004] = {0, };
ll sumTree[8000004] = {0, };

ll init(int start, int end, int index) {
    if(start == end) {
        tree[index] = cost[start-1];
        return tree[index];
    }
    int mid = (start+end) / 2;
    ll left = init(start, mid, index*2);
    ll right = init(mid+1, end, index*2+1);
    return tree[index] = ((left % DIV) * (right % DIV)) % DIV;
}

void update(int start, int end, int index, int updateIdx, ll updateData) {
    if(updateIdx < start || updateIdx > end) {
        return;
    }
    if(start == end) {
        tree[index] = updateData;
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, index*2, updateIdx, updateData);
    update(mid+1, end, index*2+1, updateIdx, updateData);
    tree[index] = ((tree[index*2] % DIV) * (tree[index*2+1] % DIV)) % DIV;
}

ll sumInit(int start, int end, int index) {
    if(start == end) {
        sumTree[index] = arr[start-1];
        return sumTree[index];
    }
    int mid = (start+end) / 2;
    ll left = init(start, mid, index*2);
    ll right = init(mid+1, end, index*2+1);
    return sumTree[index] = left + right;
}

ll find(int start, int end, int index, int left, int right) {
    if(end < left || start > right) { return 0; }
    if(start >= left && end <= right) {
        return sumTree[index];
    } 
    int mid = (start+ end) / 2;
    return find(start, mid, index*2, left, right) + find(mid+1, end, index*2+1, left, right);
}


int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    sumInit(1, N, 1);
    for(int i=0; i<N; i++) {
        update(1, N, 1, i+1, find(1, N, 1, 1, i+1));
    }
    cout << tree[1];
}