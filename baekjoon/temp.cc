#include <bits/stdc++.h>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int idx = 0;
    int back = section.back();
    while(1) {
        if(back - m + 1 <= section[idx]) {
            ++answer;
            break;
        }
        int end = section[idx] + m - 1;
        int start = section[idx];
        while(section[idx] <= end) {
            idx++;
        }
        ++answer;
    }
    return answer;
}