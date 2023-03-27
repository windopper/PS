#include <bits/stdc++.h>
using namespace std;
int N;
vector<double> perc;
vector<vector<int>> edges;
int dis[101];
int sccId[101];
int n = 0, sccCnt = 1;
vector<vector<int>> sccs;
stack<int> st;

int tarjan(int cur) {
  dis[cur] = ++n;
  int ret = dis[cur];
  st.push(cur);
  for (auto next : edges[cur]) {
    if (!dis[next]) ret = min(ret, tarjan(next));
    if (!sccId[next]) ret = min(ret, dis[next]);
  }
  if (ret == dis[cur]) {
    vector<int> cycle;
    while (1) {
        int t = st.top();
        st.pop();
        sccId[t] = sccCnt;
        cycle.push_back(t);
        if (cur == t)
            break;
    }
    sccs.push_back(cycle);
    ++sccCnt;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed, cout.precision(7);
  while (1) {
    cin >> N;
    if (N == 0)
      break;
    perc.assign(N+1, 0);
    edges.assign(N + 1, vector<int>());
    memset(dis, 0, sizeof(dis));
    memset(sccId, 0, sizeof(sccId));
    sccs.clear();
    n = 0;
    sccCnt = 1;
    for (int i = 1; i < N + 1; i++) {
        double p;
        int a;
        cin >> p >> a;
        perc[i] = p;
        for (int j = 0; j < a; j++) {
            int tmp;
            cin >> tmp;
            edges[i].push_back(tmp);
        }
    }

    for (int i = 1; i < N + 1; i++) {
        if (dis[i]) continue;
        tarjan(i);
    }

    int indegree[101] = {0, };
    for(int i=1; i<N+1; i++) {
        for(int next : edges[i]) {
            if(sccId[next] != sccId[i]) {
                ++indegree[sccId[next]];
            }
        }
    }
    double ans = 1;
    double p = 1;
    for(int i=1; i<sccCnt; i++) {
        double p = 1;
        if(indegree[i] == 0) {
            for(int next : sccs[i-1]) {
                p *= perc[next];
            }
            ans *= 1 - p;
        }
    }

    cout << ans << "\n";
  }
}