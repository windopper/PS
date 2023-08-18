#include <bits/stdc++.h>

using namespace std;
int N;

string s;
int curCnt = 0;
map<char, int> visited;
int ans = 0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    cin >> s;

    int left = 0;
    int right = 0;
    while(left <= right) {
        if (right >= s.size()) break;

        char currentChar = s[left];
        char nextChar = s[right];

        if (curCnt < N) {
            if (visited[nextChar]) {
                visited[nextChar]++;
                right++;
            }
            else {
                visited[nextChar] = 1;
                curCnt++;
                right++;
            }
        }
        else if (curCnt == N) {
            if (visited[nextChar]) {
                visited[nextChar]++;
                right++;
            }
            else {
                visited[currentChar] -= 1;
                if (visited[currentChar] == 0) curCnt--;
                left++;
            }
        }
        ans = max(ans, right - left);
    }

    cout << ans;
}