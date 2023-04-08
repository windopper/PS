#include <bits/stdc++.h>

using namespace std;

string fn(string s) {
    if(s.size() == 1) {
        return "0" + s;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<pair<int, int>> arr;
    for(int i=0; i<N; i++) {
        int a; string b;
        cin >> a >> b;
        int p = 0;
        p += stoi(b.substr(0, 2)) * 60;
        p += stoi(b.substr(3, 2));
        arr.push_back({p, a});
    }

    sort(arr.begin(), arr.end());
    int as = 0;
    int bs = 0;
    int time = -1;
    int atime = 0;
    int btime = 0;
    for(int i=0; i<N; i++) {
        int team = arr[i].second;

        if(team == 2) {
            ++bs;
            if(as == bs) {
                atime += arr[i].first - time;
                time = -1;
            }
        }
        else if(team == 1) {
            ++as;
            if(as == bs) {
                btime += arr[i].first - time;
                time = -1;
            }
        }

        if(as < bs && time == -1) {
            time = arr[i].first;
        }
        else if(as > bs && time == -1) {
            time = arr[i].first;
        }
    }

    if(time == -1) time = 0;

    if(as > bs) {
        atime += 48 * 60 - time;
    }
    if(as < bs) {
        btime += 48 * 60 - time;
    }

    cout << fn(to_string(atime / 60)) + ":" + fn(to_string(atime % 60)) << "\n";
    cout << fn(to_string(btime / 60)) + ":" + fn(to_string(btime % 60)) << "\n";
}