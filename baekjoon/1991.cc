#include <bits/stdc++.h>

using namespace std;
int N;
map<char, vector<char>> graph;

void preorder(char x) {
    char a = graph[x][0];
    char b = graph[x][1];
    cout << x;
    if(a != '.') preorder(a);
    if(b != '.') preorder(b);
}

void inorder(char x) {
    char a = graph[x][0];
    char b = graph[x][1];
    if(a != '.') inorder(a);
    cout << x;
    if(b != '.') inorder(b);
}

void postorder(char x) {
    char a = graph[x][0];
    char b = graph[x][1];
    if(a != '.') postorder(a);
    if(b != '.') postorder(b);
    cout << x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1; i<N+1; i++) {
        char a, b, c;
        vector<char> vec;
        cin >> a >> b >> c;
        vec.push_back(b); vec.push_back(c);
        graph[a] = vec;
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
}