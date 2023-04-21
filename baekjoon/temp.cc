#include <bits/stdc++.h>

using namespace std;

struct info {
    string name;
    int y, m, d;
};

bool compare(info& a, info& b) {
    if(a.y != b.y) return a.y < b.y;
    if(a.m != b.m) return a.m < b.m;
    return a.d < b.d;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<info> arr;
    while(n--) {
        string s;
        int d, m, y;
        cin >> s >> d >> m >> y;
        arr.push_back({s, y, m, d});
    }

    sort(arr.begin(), arr.end(), compare);

    cout << arr.back().name << '\n' << arr[0].name;
}