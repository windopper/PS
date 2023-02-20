#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int m, n;
vector<pair<int, pair<int, int>>> arr;
int parent[2000001];

int find(int x) {
  if (x == parent[x])
    return x;
  return parent[x] = find(parent[x]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while (true) {
    cin >> m >> n;
    if (m == 0 && n == 0)
      return 0;

    arr.clear();
    int maxCost = 0;

    for (int i = 0; i < m; i++) {
      parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      arr.push_back({z, {x, y}});
      maxCost += z;
    }

    sort(arr.begin(), arr.end());

    int curCost = 0;
    for (int i = 0; i < arr.size(); i++) {
      int dist = arr[i].first;
      int a = arr[i].second.first;
      int b = arr[i].second.second;
      a = find(a);
      b = find(b);
      if (a != b) {
        if (a < b)
          parent[b] = a;
        else
          parent[a] = b;
        curCost += dist;
      }
    }

    cout << maxCost - curCost << "\n";
  }
}