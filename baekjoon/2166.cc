#include <bits/stdc++.h>

using namespace std;
int N;
vector<pair<double, double>> coords;

double ccw(double x1, double x2, double x3, double y1, double y2, double y3) {
    double tmp = (x1*y2) + (x2*y3) + (x3*y1);
    tmp -= (x2*y1) + (x3*y2) + (x1*y3);
    return tmp / 2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) {
        double a, b;
        cin >> a >> b;
        coords.push_back({a, b});
    }
    double res = 0;
    for(int i=1; i<coords.size(); i++) {
        res += ccw(coords[0].first, coords[i-1].first, coords[i].first, coords[0].second,
                coords[i-1].second, coords[i].second);
    }
    printf("%.1lf", abs(res));
}