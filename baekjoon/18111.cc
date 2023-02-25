#include <bits/stdc++.h>
#include <limits>

using namespace std;
int N, M, B;
int mih = 256;
int mah = 0;
int heights = 0;
int T = numeric_limits<int>::max();
vector<vector<int>> arr;

void find(int targeth) {
    int estimate = 0;
    int useBlock = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            // 기준보다 땅이 낮을 경우 
            if(arr[i][j] < targeth) {
                useBlock += targeth - arr[i][j];
                ++estimate;
            }
            // 기준보다 땅이 높을 경우
            else if(arr[i][j] > targeth) {
                useBlock -= arr[i][j] - targeth;
                estimate += 2;
            }
        }
    }
    
    // 사용한 블록이 가지고 있는 블록보다 크면 기록 등록 취소
    if(useBlock > B) return;
    if(T > estimate) {
        T = estimate;
        heights = targeth;
        return;
    }
    // 기록이 같으면 높이 비교
    if(T == estimate) {
        heights = max(heights, targeth);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> B;
    for(int i=0; i<N; i++) {
        vector<int> vec;
        for(int j=0; j<M; j++) {
            int tmp; cin >> tmp;
            mih = min(mih, tmp);
            mah = max(mah, tmp);
            vec.push_back(tmp);
        }
        arr.push_back(vec);
    }

    for(int i=mih; i<=mah; i++) {
        find(i);
    }
    cout << T << " " << heights;
}