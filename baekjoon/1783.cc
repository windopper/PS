#include <iostream>
using namespace std;
long long n, m;

long long solve() {
    if (n > 2) {
        if (m <= 6) {
            return min(m-1, 3LL);
        }
        else {
            return 4LL + (m - 7);
        }
    }
    else if (n==2) {
        if (m <= 7) {
            return (m-1) / 2;
        }
        else {
            return 3LL;
        }
    }
    else {
        return 0;
    }
}

int main() {
    cin >> n >> m;
    cout << solve() + 1;
}