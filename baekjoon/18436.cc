#include <iostream>

#define MAX 1000000000

using namespace std;
int N, M;
int oTree[1000000001] = {
    0,
};
int eTree[1000000001] = {
    0,
};

void _oddUpdate(int x, int diff) {
    while(x < MAX) {
      oTree[x] = oTree[x] + diff;
      x += (x & -x);
    }
}

void _evenUpdate(int x, int diff) {
    while(x < MAX) {
      eTree[x] = oTree[x] + diff;
      x += (x & -x);
    }
}

int _evenQuery(int x) {
    int res = 0;
    while(x > 0) {
      res += eTree[x];
      x -= (x & -x);
    }
    return res;
}

int _evenQuery(int x, int y) {
    return _evenQuery(y) - _evenQuery(x-1);
}

int _oddQuery(int x) {
    int res = 0;
    while(x > 0) {
      res += oTree[x];
      x -= (x & -x);
    }
    return res;
}

int _oddQuery(int x, int y) { return _oddQuery(y) - _oddQuery(x - 1); }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        int tmp;
        cin >> tmp;
        if(tmp % 2 == 0) {
            _evenUpdate(tmp, 1);
        }
        else {
            _oddUpdate(tmp, 1);
        }
    }
    cin >> M;
    for(int i=0; i<M; i++) {
        //query
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            // update   
            if(b % 2 == 0) {
                _evenUpdate(b, -1);
                _evenUpdate(c, 1);
            }
            else {
                _oddUpdate(b, -1);
                _oddUpdate(c, 1);
            }
        }
        else if(a == 2) {
            // even
            cout << _evenQuery(b, c) << "\n";
        }
        else {
            // odd
            cout << _oddQuery(b, c) << "\n";
        }
    }
}