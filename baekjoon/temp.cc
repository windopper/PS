#include <bits/stdc++.h>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < arr1.size(); i++) {
        string str = bitset<8>(arr1[i]).to_string();
        string str2 = bitset<8>(arr2[i]).to_string();

        string ans = "";

        for (int j = 0; j < n; j++) {
            if (str[j] == '0')
                ans += ' ';
            else if (str[j] == '1')
                ans += '#';
        }

        for (int k = 0; k < n; k++) {
            if (str2[k] == '0')
                ans[k] = ' ';
            else if (str2[k] == '1')
                ans[k] = '#';
        }

        answer.push_back(ans);
    }

    return answer;
}