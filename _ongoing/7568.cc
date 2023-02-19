#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int N;
vector<pair<int, int>> arr;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;

    for(int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});
    }

    vector<pair<int, int>> copied = arr;
    map<pair<int, int>, int> ranks;
    sort(copied.begin(), copied.end(), greater<>());

    int rank = 1;
    for(int i=0; i<copied.size(); i++) {
        int x = copied[i].second;
        bool isTop = true;
        for(int j=0; j<copied.size(); j++) {
            int y = copied[j].second;
            if(x < y) {
                isTop = false;
                break;
            };
        }

        if(isTop) {
            ranks[copied[i]] = rank;
            rank++;
        }
        else {
            ranks[copied[i]] = i+1;
        }
    }

    for(int i=0; i<arr.size(); i++) {
        cout << ranks[arr[i]] << " ";
    }
}