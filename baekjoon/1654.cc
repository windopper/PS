#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;
int n, k;
vector<long long> lines;

int check(long long length) {
    long long total = 0;
    for(int i=0; i<lines.size(); i++) {
        total += lines[i] / length;
    }
    if(total >= k) {
        // 더 많이 쪼갰을 때
        return 1;
    }
    else {
        return -1;
    }
}

int main() {
    
    cin >> n >> k;

    for(int i=0; i<n; i++) { 
        int a;
        cin >> a;
        lines.push_back(a);
    }

    long long start = 1;
    long long end = *max_element(lines.begin(), lines.end());
    long long mid;
    long long ans = 0;
    while (start <= end) {
        mid = ((long long)start + end) / 2;
        //cout << start << " " << mid << " " << end << "\n";
        int status = check(mid);
        if(status == 1) {
            start = mid+1;
            ans = max(ans, mid);
        }
        else if(status == -1) {
            end = mid-1;
        }
    }
    cout << ans;
}