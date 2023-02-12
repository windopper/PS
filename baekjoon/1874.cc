#include <algorithm>
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);

    cin >> m;
    for (int i=0; i<m; i++) {
        int tmp;
        cin >> tmp;

        int left = 0;
        int right = n-1;
        bool exist = false;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if(a[mid] < tmp) {
                left = mid+1;
            }
            else if(a[mid] > tmp) {
                right = mid-1;
            }
            else {
                cout << 1 << "\n";
                exist = true;
                break;
            }
        }
        if (!exist) {
            cout << 0 << "\n";
        }
    }

    return 0;
}