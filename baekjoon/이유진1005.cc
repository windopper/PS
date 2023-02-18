#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int t = 0;
int weight[1001]{};
int dp[1001]{};
vector<vector<int>> vec(1001, vector<int>(1001, 0));

int find(int x)
{
    if (vec[x][0] == 0)
        return dp[x] = weight[x];

    if (dp[x] == -1)
    {
        int max_find = 0;
        for (int d = 1; d < vec[x][0] + 1; d++)
        {
            if (dp[vec[x][d]] > -1)
            {
                max_find = max(dp[vec[x][d]], max_find);
                continue;
            }
            max_find = max(find(vec[x][d]), max_find);
        }
        dp[x] = weight[x] + max_find;
    }
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

            dp[k] = -1;
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
        cout << find(object) << '\n';
    }
    return 0;
}