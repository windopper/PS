#include <bits/stdc++.h>

using namespace std;
struct Node {
    int floor = -1;
    string name;
    vector<Node*> nxt;

    Node() {

    }

    Node(string x) {
        this->name = x;
    }

    Node* findOrCreate(string x) {
        for(int i=0; i<nxt.size(); i++) {
            if(nxt[i]->name == x) return nxt[i];
        }
        Node* newNode = new Node(x);
        newNode->floor = this->floor + 1;
        this->nxt.push_back(newNode);
        return newNode;
    }
};

void dfs(Node* node) {
    for(int i=0; i<node->floor; i++) {
        cout << "--";
    }
    cout << node->name<< "\n";

    sort(node->nxt.begin(), node->nxt.end(), [](Node* a, Node* b) {
        return a->name < b->name;
    });

    for(int i=0; i<node->nxt.size(); i++) {
        dfs(node->nxt[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    Node *root = new Node();

    for(int i=0; i<N; i++) {
        int t;
        cin >> t;
        vector<string> arr(t);
        for(int j=0; j<t; j++) {
            cin >> arr[j];
        }

        Node *cur = root;

        for(int j=0; j<t; j++) {
            Node* node = cur->findOrCreate(arr[j]);
            cur = node;
        }
    }

    sort(root->nxt.begin(), root->nxt.end(), [](Node* a, Node* b) {
        return a->name < b->name;
    });
    for(int i=0; i<root->nxt.size(); i++) {
        dfs(root->nxt[i]);
    }
}