#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int w, h, x, y, p;

bool isInSquare(int *loc)
{
    int locX = *loc;
    int locY = *(loc + 1);
    if (locX >= x && locX <= x + w && locY >= y && locY <= y + h)
    {
        return true;
    }
    return false;
}

bool isInCircle(int *loc)
{
    int locX = *loc;
    int locY = *(loc + 1);
    if (locX >= x && locX <= x + w && locY >= y && locY <= y + h)
    {
        return false;
    }
    if (locX < x)
    {
        double cX = -(sqrt(pow(h / 2, 2) - pow(locY - y - h / 2, 2))) + x;
        if (locX >= cX)
        {
            return true;
        }
    }
    else if (locX > x + w)
    {
        double cX = sqrt(pow(h / 2, 2) - pow(locY - y - h / 2, 2)) + x + w;
        if (locX <= cX)
        {
            return true;
        }
    }

    return false;
}

int main()
{

    cin >> w >> h >> x >> y >> p;
    int loc[p][2];
    int cnt = 0;
    for (int i = 0; i < p; i++)
    {
        cin >> loc[i][0] >> loc[i][1];
        if (isInCircle(loc[i]) || isInSquare(loc[i]))
        {
            cnt += 1;
        }
    }
    cout << cnt;
    return 0;
}