#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long int ll;
using namespace std;

#define DIV 1000000007
#define MAX 200001

int N;
ll cntTree[MAX] = {0, };
ll sumTree[MAX] = {0, };

void updateCnt(int x) {
    while (x <= MAX) {
        cntTree[x] += 1;
        x += (x & -x);
    }
}

void updateSum(int x, int diff) {
    while (x <= MAX) {
        sumTree[x] += diff;
        x += (x & -x);
    }
}

int findCnt(int x) {
    int res = 0;
    while ( x > 0 ) {
        res += cntTree[x];
        x -= (x & -x);
    }
    return res;
}

int findCnt(int x, int y) {
    return findCnt(y) - findCnt(x-1);
}

ll findSum(int x) {
    ll res = 0;
    while ( x > 0 ) {
        res += sumTree[x];
        x -= (x & -x);
    }
    return res;
}

ll findSum(int x, int y) {
    return findSum(y) - findSum(x-1);
}
    
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    ll ans = 1;
    for(int i=1; i<N+1; i++) {
        int tmp;
        cin >> tmp;
        ++tmp;
        if( i > 1 ) {
            ll leftCnt = findCnt(tmp - 1);
            ll leftSum = findSum(tmp - 1);

            ll rightCnt = findCnt(tmp+1, MAX);
            ll rightSum = findSum(tmp+1, MAX);

            ll lcost = tmp * leftCnt - leftSum;
            ll rcost = rightSum - tmp * rightCnt;

            lcost %= DIV;
            rcost %= DIV;
            ll res = (lcost + rcost) % DIV;
            ans *= res;
            ans %= DIV;
        }
        updateCnt(tmp);
        updateSum(tmp, tmp);
    }

    cout << ans % DIV;

    return 0;
}