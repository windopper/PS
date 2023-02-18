#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> person;
int parent[200001];
int friendNum[200001];
int F, T;

int find(int x) {
    if ( x == parent[x] ) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    map<string, int>::iterator iter;
    cin >> T;
    for(; T>0; T--) {
        // 테스트 케이스 시작
        int idx = 0;
        for(int i=0; i<200001; i++) {
            // 초기화
            parent[i] = i; 
            friendNum[i] = 1;
        }

        cin >> F;
        // 친구 관계 수
        for(; F>0; F--) {
            string a, b;
            int x, y;
            cin >> a >> b;

            iter = person.find(a);
            if(iter == person.end()) {
                // 존재하지 않는 사람이라면
                person[a] = ++idx;
                x = idx;
            }
            else x = iter->second;

            iter = person.find(b);
            if(iter == person.end()) {
                // 존재하지 않는 사람이라면
                person[b] = ++idx;
                y = idx;
            }
            else y = iter->second;

            int rootX = find(x);
            int rootY = find(y);
            if(rootX != rootY) {
                // 서로 다른 집합 이라면
                if(rootX < rootY) {
                    // 인덱스가 낮은 쪽으로 결합
                    parent[rootY] = rootX;
                    friendNum[rootX] += friendNum[rootY];
                }
                else {
                    parent[rootX] = rootY;
                    friendNum[rootY] += friendNum[rootX];
                }
            }

            cout << friendNum[parent[rootX]] << "\n";
        }
    }
}