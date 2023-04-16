#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int K;
    cin >> K;
    stack<int> st;
    long long sum = 0;
    while(K--) {
        int t;
        cin >> t;
        if(t == 0) {
            sum -= st.top();
            st.pop();   
        }
        else {
            sum += t;
            st.push(t);
        }
    }

    cout << sum;
}