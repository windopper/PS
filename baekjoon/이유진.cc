#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int sam = 1;
int tes = 0;
int parent[100010]{};
int weight[100010]{};

int find(int x, int y)
{
    if (x == parent[x])
    {
        return x;
    } // weight 값이 부모에게 있다는 것 자체가 업데아트가 안되었다는 뜻임
    weight[x] += weight[parent[x]];
    parent[x] = find(parent[x], x);
    return parent[x];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {

        cin >> sam >> tes;

        if (sam == 0)
        {
            break;
        }

        for (int i = 1; i < sam + 1; i++)
        {
            parent[i] = i;
            weight[i] = 0;
        }

        for (int i = 0; i < tes; i++)
        {

            char k;
            int s1 = 0;
            int s2 = 0;
            int w = 0;

            cin >> k >> s1 >> s2;

            int fs1 = find(s1, s1);
            int fs2 = find(s2, s2);

            if (k == '!')
            {

                cin >> w;
                if (fs1 != fs2)
                { // s1을 모르면
                    parent[fs2] = fs1;
                    // weight[fs2] = w - weight[s2] + weight[s1];
                    weight[fs2] = weight[s1] - weight[s2] + w;
                }
            }
            else
            { // ?를 받았을때
                if (fs1 == fs2)
                {
                    cout << weight[s2] - weight[s1] << "\n";
                }
                else
                {
                    cout << "UNKNOWN"
                         << "\n";
                }
            }
        }
    }
}