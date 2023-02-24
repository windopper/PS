#include <bits/stdc++.h>

using namespace std;
// -1 답이 아직 계산되지 않음
// 0 해당 입력들이 서로 대응되지 않음
// 1 해당 입력들이 서로 대응됨
int cache[101][101];
int C;
string W, S;

bool match(int w, int s) {

    int& ret = cache[w][s];
    if(ret != -1) return ret;

    while (w < W.size() && s < S.size() &&
        (W[w] == '?' || W[w] == S[s])) {
        // asterisk를 만날 때 까지 혹은 두 문자열이 일치하지 않을 때 까지
        // 또는 두 문자열 중 하나가 끝에 도달할 때 까지 순회한다.
        ++s;
        ++w;
    }

    // 패턴 끝에 도달해서 끝난 경우 문자열 또한 끝났는지 확인
    if (w == W.size())
      return ret = (s == S.size());

    // *을 만나서 끝난 경우 *에 몇 글자를 대응해야 할지 재귀호출하면서 확인
    if (W[w] == '*') {
        for (int skip = 0; s + skip <= S.size(); skip++) {
            // * 이후의 패턴에 대해 문자열이 대응되는지 완전탐색
            if (match(w+1, skip+s)) {
                return ret = 1;
            }
        }
    }
    return ret = 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> C;
    for(; C>0; C--) {
        vector<string> vec;
        cin >> W;
        int N;
        cin >> N;
        for(int i=0; i<N; i++) {
            cin >> S;
            for (int i = 0; i < 101; i++) {
                for (int j = 0; j < 101; j++)
                    cache[i][j] = -1;
            }
            if(match(0, 0)) {
                // cout << S << "\n";
                vec.push_back(S);
            }
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << "\n";
    }
}