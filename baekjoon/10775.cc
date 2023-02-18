#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int G, P;
vector<int> planes;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> G >> P;
    for(int i=0; i<P; i++) {
        int temp;
        cin >> temp;
        planes.push_back(temp);
    }

    //sort(planes.begin(), planes.end(), greater<>());

    int cnt = 0;
    int curGate = G;
    for(int i=0; i<planes.size(); i++) {
        int plane = planes[i];
        if (curGate >= plane) {
            curGate = plane - 1;
            cnt++;
        }

        if (curGate <= 0) break;
    }

    cout << cnt << "\n";

}