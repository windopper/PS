#include <bits/stdc++.h>

using namespace std;

struct Seg {
    int tree[1<<18];
    int sz = 1 << 17;

    void update(int x, int v) {
        x |= sz;
        tree[x] += v;
        while(x >>= 1) {
            tree[x] = tree[x<<1] + tree[x<<1 | 1];
        }
    }

    int query(int l, int r) {
        l |= sz;
        r |= sz;
        int ret = 0;
        while(l <= r) {
            if(l & 1) ret += tree[l++];
            if(~r & 1) ret += tree[r--];
            l >>= 1, r >>= 1;
        }
        return ret;
    }
} seg;

const int MAXV = 400000;
int sz[MAXV], dep[MAXV], par[MAXV], top[MAXV], in[MAXV], out[MAXV];
vector<int> g[MAXV];
int pv = 0;

/*
sz[i] = i를 루트로 하는 서브트리의 크기
dep[i] = i의 깊이
par[i] = i의 부모 정점
top[i] = i가 속한 체인의 가장 위에 있는 정점
in[i], out[i] = dfs ordering
g[i] = i의 자식 정점
*/

void dfs1(int v = 1) {
    sz[v] = 1;
    for(auto &i : g[v]) {
        // 깊이 증가
        dep[i] = dep[v] + 1;
        // 부모 설정
        par[i] = v;
        dfs1(i);
        // 서브트리 크기 증가
        sz[v] += sz[i];
        // 서브 트리가 가장 큰 자식을 g[v]의 맨 앞으로 이동
        // 따라서 v에서 뻗어나가는 heavy edge는 g[v][0]가 됨
        if(sz[i] > sz[g[v][0]]) swap(i, g[v][0]);
    }
}

// dfs ordering
void dfs2(int v = 1) {
    in[v] = ++pv;
    for(auto i : g[v]) {
        // i 가 g[v]의 첫번째 자식이라면 top[v]를 물려받음
        // 그렇지 않다면 새로운 체인 시작
        top[i] = i == g[v][0] ? top[v] : i;
        dfs2(i);
    }
    out[v] = pv;
}

int query(int a, int b) {
    int ret = 0;
    // 서로 다른 종류의 체인인 경우
    while(top[a] ^ top[b]) {
        // a의 깊이가 더 깊어야 한다.
        if(dep[top[a]] < dep[top[b]]) swap(a, b);
        // a가 속한 체인의 시작점
        int st = top[a];
        // 같은 체인에 대하여 쿼리를 날림
        ret += seg.query(in[st], in[a]);
        // a가 체인의 시작점의 부모가 된다.
        a = par[st];
    }
    // a의 깊이가 더 깊어야 한다.
    if(dep[a] > dep[b]) swap(a, b);
    // 
    ret += seg.query(in[a], in[b]);
    return ret;
}