#include <bits/stdc++.h>

using namespace std;
vector<int> arr;
vector<int> dupe;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<long long> st;
    long long cnt = 0;
    dupe.assign(N, 0);
    for (int i = 0; i < N; i++) {
        long long t;
        cin >> t;
        arr.push_back(t);
        if (st.size() > 0) {
            if (arr[st.size() - 1] == t) dupe[i] = dupe[i - 1] + 1;
        }
        while (!st.empty() && st.back() < t) {
            ++cnt;
            st.pop_back();
        }
        if (st.size() > 0) {
            if (arr[st.size() - 1] == t) dupe[i] = dupe[i - 1] + 1;
        }
        int idx = st.size() - 1;
        if (!st.empty() && st.back() == t) {
            int idx = st.size() - 1 - dupe[i];
            cnt += dupe[i];
        }
        if (idx >= 0 && st[idx] > t) ++cnt;
        st.push_back(t);
    }
    cout << cnt;
}