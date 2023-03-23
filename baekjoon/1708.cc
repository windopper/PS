#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> vec;
// vector<pair<int, int>> points;

// double ccw(pair<int, int> pivot, pair<int, int> next, pair<int, int> point) {
//     pair<int, int> p12 = {next.first - pivot.first, next.second - pivot.second};
//     pair<int, int> p23 = {point.first - next.first, point.second - next.second};
//     return p12.first * p23.second - p23.first * p12.second;
// }

// double norm(double x, double y) {
//     return hypot(x, y);
// }

// // Timeout!! O(N^2)
// vector<pair<int, int>> giftWrap() {
//     int n = points.size();
//     vector<pair<int, int>> hull;
//     pair<int, int> pivot = *min_element(points.begin(), points.end());
//     hull.push_back(pivot);
//     while(1) {
//         pair<int, int> ph = hull.back(), next = points[0];
//         for(int i=1; i<n; i++) {
//             double cross = ccw(ph, next, points[i]);
//             double dist = norm(next.first - ph.first, next.second - ph.second) -
//                 norm(points[i].first - ph.first, points[i].second - ph.second);
//             if(cross > 0 || (cross == 0 && dist < 0)) 
//                 next = points[i];
//         }

//         if(next == pivot) break;
//         hull.push_back(next);

//     }
//     return hull;
// }

// graham-scan O(NlogN)

vector<pair<int, int>> p;

int N;

long long ccw(vec &a, vec &b, vec &c) {
    vec p12 = {b.first - a.first, b.second - a.second};
    vec p23 = {c.first - b.first, c.second - b.second};
    return 1LL * p12.first * p23.second - 1LL * p12.second * p23.first;
}

bool compare(vec &a,vec &b) {
    long long v = ccw(p[0], a, b);
    if(v) return v > 0;
    return a.first == b.first ? a.second < b.second : a.first < b.first;
}


stack<int> graham_scan() {
    int next = 2;

    swap(p[0], *min_element(p.begin(), p.end()));
    sort(p.begin() + 1, p.end(), compare);

    stack<int> s;

    s.push(0);
    s.push(1);

    while(next < N) {
        while(s.size() >= 2) {
            int first, second;
            second = s.top();
            s.pop();
            first = s.top();

            // 좌회전?
            if (ccw(p[first], p[second], p[next]) > 0) {
                s.push(second);
                break;
            }
        }

        s.push(next++);
    }

    return s;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   
    cin >> N;
    for(int i=0; i<N; i++) {
        long long x, y;
        cin >> x >> y;
        //points.push_back({x, y});
        p.push_back({x, y});
    }
    //cout << giftWrap().size();
    cout << graham_scan().size();
}