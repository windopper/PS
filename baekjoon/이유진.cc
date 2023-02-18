#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int t = 0;
int weight[1001]{};
int dp[1001] = {0, };
bool visited[1001] = {false, };
vector<vector<int>> vec(1001, vector<int>(1001, 0));

int find(int x)
{
    visited[x] = true;
    // 방문했구나 환영한다

    if (vec[x][0] == 0)
    // 출발 지접 도달하면 그냥 뱉음
        return dp[x];

    int max_find = 0;
    for (int d = 1; d < vec[x][0] + 1; d++)
    {
        if (visited[vec[x][d]]) {
            // 한번이라도 방문한 적이 있다면
            // 계산해두었던 값을 뱉음
            max_find = max(max_find, dp[vec[x][d]]);
            continue;
        }
        max_find = max(find(vec[x][d]), max_find);
        // 아니라면 계속 내려감
    }
    dp[x] += max_find;
    // 가장 오래걸린 시간을 저장

    return dp[x];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int n = 0;
        int m = 0;
        int object = 0;

        cin >> n >> m;

        for (int k = 1; k < n + 1; k++)
        {

            int w = 0;

            cin >> w;

            dp[k] = w;
            visited[k] = false;
            weight[k] = w;
            vec[k][0] = 0;  
        }

        for (int j = 0; j < m; j++)
        {

            int a = 0;
            int b = 0;

            cin >> a >> b;

            vec[b][0] += 1;
            vec[b][vec[b][0]] = a;
        }

        cin >> object;

        cout << find(object) << "\n";

    }
    return 0;
}