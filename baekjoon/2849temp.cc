#include<bits/stdc++.h>
#define INF 2147483647
#define rv 0 // right val 
#define rc 1 // right char
#define lv 2 // left val
#define lc 3 // left char
#define v 4 // val
#define p 5 // 구간전체가 배열인지
#define Rig 19
#define Lef 18


using namespace std;

int N,K;
int tree[800004][6]{}; // 오른쪽밸류, 오른쪽문자, 왼쪽밸류, 왼쪽문자, 밸류, 완전배열여부
int arr[200001]{};


void Init(int s, int e, int node){
	
	if(s == e){	
		int m2[6] = {1, Lef, 1, Lef, 1, 1}; // 다 왼쪽값으로 초기화함 
		for(int i=0; i<6; i++){
			tree[node][i] = m2[i];
		}
		return;
	}
	
	int m = (s+e)/2;
	
	Init(s, m, node*2);
	Init(m+1, e, node*2+1);
	
	int tmp = max(tree[node*2][v], tree[node*2+1][v]); // 둘중 더 큰 밸류값을 가진다
	int isPer = 0;                                     // 완전배열인지 아직알수없다
	int right_val = tree[node*2+1][rv];             //  오른쪽 값은 만약통합가능하고 오른쪽배열이 완전배열이면 증가하고 그렇지 않으면 오른쪽을 따른다
	int left_val = tree[node*2][lv];              // 왼쪽배열도 마찬가지이다
	
	if(tree[node*2][rc] != tree[node*2+1][lc]){ // 연결가능하면
		int fusion_val = tree[node*2][rv]+tree[node*2+1][lv]; // 연결해본다 왼쪽의 오른쪽값과 오른쪽의 왼쪽값을 더한다
		if(tree[node*2][p] && tree[node*2+1][p]) isPer = 1;    // 연결가능한데 둘다 완전배열이면 이것도 완전배열이다
		if(tree[node*2][p]) left_val = fusion_val;            // 왼쪽이 완전배열이면 왼쪽값이 증가한다
		if(tree[node*2+1][p]) right_val = fusion_val;        // 오른쪽이 완전배열이면 오른쪽값이 증가한다
		tmp = max(tmp, fusion_val);                       // 합친값보다 기존값이 더 클수도 있잖아
	}
	
	int m1[6] = {right_val, tree[node*2+1][rc], left_val, tree[node*2][lc], tmp, isPer};
	for(int i=0; i<6; i++){
		tree[node][i] = m1[i];
	}
	return;
}

void Update(int s, int e, int node, int index){
	
	if(index < s || index > e) return;
	
	if(s == e){
		int m2[6] = {1, arr[s], 1, arr[s], 1, 1};
		for(int i=0; i<6; i++){
			tree[node][i] = m2[i];
		}
		return;
	}
	
	int m = (s+e)/2;
	
	Update(s, m, node*2, index);
	Update(m+1, e, node*2+1, index);
	
	int tmp = max(tree[node*2][v], tree[node*2+1][v]); // 둘중 더 큰 밸류값을 가진다
	int isPer = 0;
	int right_val = tree[node*2+1][rv];
	int left_val = tree[node*2][lv];
	
	if(tree[node*2][rc] != tree[node*2+1][lc]){ // 연결가능하면
		int fusion_val = tree[node*2][rv]+tree[node*2+1][lv]; // 연결해본다
		if(tree[node*2][p] && tree[node*2+1][p]) isPer = 1;
		if(tree[node*2][p]) left_val = fusion_val; 
		if(tree[node*2+1][p]) right_val = fusion_val; 
		tmp = max(tmp, fusion_val);
	}
	int m1[6] = {right_val, tree[node*2+1][rc], left_val, tree[node*2][lc], tmp, isPer};
	for(int i=0; i<6; i++){
		tree[node][i] = m1[i];
	}
	
	return;

}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for(int i=1; i<N+1; i++){ // 모두 왼쪽값으로 초기화
		arr[i] = Lef;
	} 
	
	Init(1, N, 1);
	
	// 왼쪽이면 오른쪽으로 오른쪽이면 왼쪽으로 바꿈
	for(int i=0; i<K; i++){
		int b;
		cin >> b;
		if(arr[b] == Lef) arr[b] = Rig;
		else arr[b] = Lef;
		Update(1, N, 1, b);
		
		cout << tree[1][v] << '\n';
	}
	
 }