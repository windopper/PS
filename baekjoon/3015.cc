#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    stack<long long> st;
    long long cnt = 0;
    for(int i=0; i<N; i++) {
        long long t;
        cin >> t;
        if(!st.empty()) {
            while(!st.empty() && st.top() < t) {
                ++cnt;
                st.pop();
            }
            if(!st.empty() && st.top() >= t) {
                ++cnt;
            }   
            if(!st.empty()) cout << st.top() << "\n";
        }
        st.push(t);
    }
    cout << cnt;
}