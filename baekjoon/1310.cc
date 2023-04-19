#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct vec {
    ll x;
    ll y;
    vec operator - (vec& rhs) {
        return { x - rhs.x, y - rhs.y };
    }
    bool operator < (vec& rhs) {
        if(y != rhs.y) return y < rhs.y;
        return x < rhs.x;
    }
    long long cross(vec& rhs) {
        return x * rhs.y - y * rhs.x;
    }
    long long dist() {
        return x * x + y * y;
    }
};


long long ccw(vec a, vec b) {
    return a.cross(b);
}

ll ccw(vec p, vec a, vec b) {
    return ccw(a-p, b-p);
}
vec s;

bool compare(vec& a, vec& b) {
    if(ccw(a-s, b-s) != 0) return ccw(a-s, b-s) > 0;
    return a < b;
}

vector<int> convex_hull(vector<vec>& p) {
    sort(p.begin(), p.end());
    s = p[0];
    sort(p.begin() + 1, p.end(), compare);
    vector<int> ret = {0, 1};
    for(int i=2; i<p.size(); i++) {
        while(ret.size() >= 2) {
            int last1 = *(ret.end() - 1);
            int last2 = *(ret.end() - 2);
            if(ccw(p[last2], p[last1], p[i]) > 0) break;
            ret.pop_back();
        }
        ret.push_back(i);
    }
    return ret;
}

vec ans1, ans2;

long long rotating_calipers(vector<vec>& p) {
    vector<int> ch = convex_hull(p);
    vector<vec> cx;
    for(int i : ch) cx.push_back(p[i]);
    int p1 = 0, p2 = 1;
    long long maxv = (cx[p1] - cx[p2]).dist();
    ans1 = cx[p1];
    ans2 = cx[p2];
    for(int i=0; i<cx.size()*2; i++) {
        int np1 = (p1 + 1) % cx.size();
        int np2 = (p2 + 1) % cx.size();
        long long tmp = ccw(cx[np1] - cx[p1], cx[p2] - cx[np2]);
        if(tmp > 0) p1 = np1;
        else if(tmp < 0) p2 = np2;
        else {
            p1 = np1;
            p2 = np2;
        }

        long long nowv = (cx[p1] - cx[p2]).dist();
        if(maxv < nowv) {
            maxv = nowv;
            ans1 = cx[p1];
            ans2 = cx[p2];
        }
    }

    return maxv;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<vec> p;
    for(int i=0; i<N; i++) {
        long long x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }

    cout << rotating_calipers(p);
}