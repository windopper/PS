#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n;
long long height[100001];
long long tree[1000001];
long long ans;

int init(int start, int end, int index) {
    if (start == end) {
        tree[index] = start;
        return tree[index];
    }
    int mid = (start + end) / 2;
    long long l = init(start, mid, index*2);
    long long r = init(mid+1, end, index*2+1);
    //cout << l << " " << r << "\n";
    tree[index] = height[l] > height[r] ? r : l;
    return tree[index];
}

int query(int start, int end, int index, int left, int right) {
    
    if (right < start || left > end) {
        return -1;
    }
    if (start >= left && end <= right) {
        return tree[index];
    }

    int mid = (start + end) / 2;
    long long l = query(start, mid, index*2, left, right);
    long long r = query(mid+1, end, index*2+1, left, right);
    if (l == -1) {
        return r;
    }
    else if (r == -1) {
        return l;
    }
    else {
        return height[r] > height[l] ? l : r;
    }
}

void dac(long long start, long long end) {

    if (start > end) return;
    int minIndex = query(0, n-1, 1, start, end);
    ans = max(ans, height[minIndex] * (end - start + 1));

    dac(start, minIndex-1);
    dac(minIndex+1, end);
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        ans = 0;
        cin >> n;
        if (n==0) break;
        for(int i=0; i<n; i++) {
            cin >> height[i];
        }
        init(0, n-1, 1);
        dac(0, n-1);
        cout << ans << "\n";
    }
}

