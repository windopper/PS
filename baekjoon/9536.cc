#include <bits/stdc++.h>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string tmp;
 
    while (getline(ss, tmp, delimiter)) result.push_back(tmp);
 
    return result;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        vector<string> records;
        string s;
        while(cin >> s) {
            records.push_back(s);
        }
        while(1) {
            string t;
            cin >> t;
            cout << t << '\n';
            if (t == "what does the fox say?") break;
            vector<string> splits = split(t, ' ');
            string sound = splits[2];

            remove(records.begin(), records.end(), sound);
        }

        for(auto& r : records) {
            cout << r << " ";
        }
        cout << "\n";
    }
}