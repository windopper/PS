#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
int siz[500001]{};
int tree[2000001]{};

int init(int start, int end, int node)
{

    if (start == end)
        return tree[node] = siz[start];
    int mid = (start + end) / 2;

    return tree[node] = init(start, mid, node*2) + init(mid + 1, end, node*2 + 1);
}

void update(int start, int end, int node, int index, int dif)
{

    if (index<start || index> end)
        return;

    tree[node] += dif;
    if (start == end)
        return;

    int mid = (start + end) / 2;
    update(start, mid, node*2, index, dif);
    update(mid + 1, end, node*2 + 1, index, dif);
}

int find(int start, int end, int node, int findt)
{

    if (start == end)
        return start;

    int mid = (start + end) / 2;
    if (tree[node*2] < findt)
    {
        return find(mid + 1, end, node*2 + 1, findt - tree[node*2]);
    }
    // 왼쪽 노드값이  찾는 값보다 더 클경우
    return find(start, mid, node*2, findt);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {

        cin >> siz[i];
    }

    cin >> M;

    init(0, N - 1, 1);

    for (int i = 0; i < M; i++)
    {

        int t = 0;

        cin >> t;

        if (t == 1)
        {

            int divs = 0;

            int w = 0;

            cin >> divs >> w;

            update(0, N - 1, 1, divs - 1, w);
        }
        else
        {

            int divs = 0;

            cin >> divs;

            cout << find(0, N - 1, 1, divs) + 1 << '\n';
        }
    }
}