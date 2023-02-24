#include <bits/stdc++.h>

using namespace std;
int N, K;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    string c;
    cin >> c;
    stack<char> s;
    for(int i=0; i<c.size(); i++) {
        while(!s.empty() && K > 0) {
            if(s.top() < c[i]) {
                s.pop();
                --K;
            }
            else {
                break;
            }
        }
        s.push(c[i]);
    }
    vector<char> arr;
    while(!s.empty()) {
        arr.push_back(s.top());
        s.pop();
    }
    for(int i=arr.size()-1; i>=0; --i) cout << arr[i];
    cout << "\n";
}