#include <bits/stdc++.h>

using namespace std;

multiset<long long> st;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int M;
    cin >> M;
    st.insert(0);
    while(M--) {
        int i;
        long long x;
        cin >> i >> x;
        if(i == 1) {
            st.insert(x);
        }
        else if(i == 2) {
            st.erase(st.find(x));
        }
        else {
            long long maxValue = 0;
            for(multiset<long long>::iterator it=st.begin(); it != st.end(); ++it) {
                long long value = (*it) ^ x;
                maxValue = max(maxValue, value);
            }
            cout << maxValue << '\n';
        }
    }
}