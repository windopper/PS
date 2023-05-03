#include <bits/stdc++.h>

using namespace std;

int combination(vector<int>& arr, int cur, int sum, int cnt) {
    if(cnt == 3) {
        return sum == 0 ? 1 : 0;
    }
    int ret = 0;
    for(int i=cur; i<arr.size(); i++) {
        ret += combination(arr, i+1, sum + arr[i], cnt + 1);
    }
    return ret;
}

int solution(vector<int> number) {
    return combination(number, 0, 0, 0);
}