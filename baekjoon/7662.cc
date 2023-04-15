#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int k;
        cin >> k;
        multiset<int> arr;
        for(int i=0; i<k; i++) {
            char c;
            int val;
            cin >> c >> val;
            if(c == 'I') {
                arr.insert(val);
            }
            else if('D') {
                if(arr.size() == 0) continue;
                if(val == -1) {
                    arr.erase(arr.begin());
                }
                else {
                    arr.erase(--arr.end());
                }
            }
        }
        if(arr.size() == 0) {
            cout << "EMPTY";
        }
        else {
            cout << *--arr.end() << " " <<  *arr.begin();
        }
        cout << '\n';
    }
}