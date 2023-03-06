#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<string> arr;
char DNA[4] = {'A', 'C', 'G', 'T'};
string ans = "";
int ansSum = 0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    arr.resize(N);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<M; i++) {
        int cnt[4];
        for(int m=0; m<4; m++) cnt[m] = 0;

        for(int j=0; j<N; j++) {
            char tmp = arr[j][i];
            switch(tmp) {
                case 'T':
                    cnt[3]++;
                    break;
                case 'A':
                    cnt[0]++;
                    break;
                case 'G':
                    cnt[2]++;
                    break;
                case 'C':
                    cnt[1]++;
                    break;
            }
        }
        int maxIndex = 0;
        int maxValue = 0;
        char maxChar;
        for(int k=0; k<4; k++) {
            if(maxValue < cnt[k]) {
                maxIndex = k;
                maxValue = cnt[k];
                maxChar = DNA[k];
            }
        }
        ans += maxChar;
        ansSum += N - cnt[maxIndex];
    }
    cout << ans << "\n" << ansSum;
}