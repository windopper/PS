#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> vec;
int N, L;
vector<vec> p;

long long ccw(vec &origin, vec &a, vec &b) {
    vec p1 = {a.first - origin.first, a.second - origin.second};
    vec p2 = {b.first - origin.first, b.second - origin.second};
    return 1LL * p1.second * p2.first - 1LL * p1.first * p2.second;
}

bool compare(vec &a, vec &b) {
    long long v = ccw(p[0], a, b);
    if(v) return v > 0;
    return a.second == b.second ? a.first > b.first : a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> L;
    for(int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        p.push_back({x,y});
    }

    swap(p[0], *min_element(p.begin(), p.end()));
    sort(p.begin() + 1, p.end(), compare);

    int next = 2;
    stack<int> st;

    while(next < N) {
        while(st.size() >= 2) {
            int first, second;
            second = st.top();
            st.pop();
            first = st.top();

            if(ccw(p[first], p[second], p[next]) > 0) {
                st.push(second);
                break;
            }
        }

        st.push(next++);
    }

    long double ans = 0;

    int first = st.top();
    st.pop();
    int second = st.top();
    st.pop();
    while(!st.empty()) {
        int third = st.top();
        st.pop();
        long double a = pow(p[third].first - p[second].first, 2);
        long double b = pow(p[third].second - p[second].second, 2);
        ans += sqrt(a + b);
    }

    cout << ans;
}