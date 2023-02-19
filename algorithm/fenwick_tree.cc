/*
    펜윅트리 ( Binary Indexed Tree )
    
    - References
    - https://www.acmicpc.net/blog/view/21
*/

int tree[999];

int sum(int i) {
    int ans = 0;
    while ( i > 0 ) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

int sum(int i, int j) {
    return sum(j) - sum(i-1);
}

void update(int i, int diff) {
    while ( i < 999 ) {
        tree[i] += diff;
        i += (i & -i);
    }
}