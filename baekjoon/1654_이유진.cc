#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

int N,K;
int lines[10001]{};
long long ans = 0;

long long finding(long long start, long long end){

    long long mid = (start+end)/2;
    // 기저조건 : start가 더 기면 안됭
    if(start > end) return mid;

    long long sum = 0;
    // 같은 개수로 쪼개는 것중에 제일 긴놈이 정답
    long long ans = 0;

    for(int i=0; i<K; i++){
        sum += lines[i] / mid;
    }

    // 더 많은 개수로 쪼개면 쪼개는 길이를 더 크게
    // 같은 개수로 쪼개는데 쪼개는 길이가 더 긴것도 있을수도?
    if(sum >= N){
        // 이 코드가 왜 항상 가장 긴 길이를 리턴하는 이유
        // mid가 가장 긴 길이라면 mid+1 이상 부터 sum < N이므로
        // 그 시점 부터 start ~ mid-1 범위만 탐색하므로 절대 가장 긴 길이를 찾을 수 없다
        // 따라서 mid가 가장 긴 길이
        ans = max(mid, finding(mid+1, end));
    }
    // 더 적은 개수로 쪼개면 쪼개는 길이를 더 짧게
    else{
        // 이 코드가 왜 항상 가장 긴 길이를 리턴하는 이유
        // start ~ mid-1 중에 가장 긴 길이를 X라고 하면
        // X 초과의 길이부터 sum < N이므로
        // 그 시점 부터 X-1 이하의 범위만 탐색하므로 X보다 가장 긴 길이를 찾을 수 없다
        ans = max(finding(start, mid-1), ans);
    }
    return ans;
}

int main(){

    cin >> K;
    cin >> N;

    for(int i=0; i<K; i++){
        cin >> lines[i];
    }

    cout << finding(1, *max_element(lines, lines+K));
}