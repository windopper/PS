#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N, M;
  cin >> N >> M;

  string s1[10], s2[10];
  for(int i=0; i<N; i++) {
    cin >> s1[i];
  }
  for(int i=0; i<N; i++) {
    cin >> s2[i];
  }

  int i = 0;
  bool ans = true;
  for (int j = 0; j < N; j++) {
    for(int l=0; l<s2[j].size(); l++) {
        if (s1[j][i] != s2[j][l]) {
            ans = false;
            break;
        }
        if (l != 0 && l % 2 == 1) ++i;
    }
    i = 0;
  }

  if (ans) {
    cout << "Eyfa";
  } else {
    cout << "Not Eyfa";
  }
  cout << "\n";
}