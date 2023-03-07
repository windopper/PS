#include <bits/stdc++.h>

using namespace std;

int T;
struct node {
    char key;
    map<char, node> children;
    string data;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (; T > 0; --T) {
        int n;
        cin >> n;
        node *root = new node();
        vector<string> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        bool isConsistent = true;

        for (int i = 0; i < n; i++) {
            node *next = root;
            string s = arr[i];
            for (int j = 0; j < s.size(); j++) {
                // 받은 값 순회
                if (next->children.find(s[j]) != next->children.end()) {
                    // 트라이 노드에 해당 값이 있다면
                    next = &next->children[s[j]];

                    if (j == s.size() - 1) {
                        // 근데 마지막 값에 도달했다면?
                        next->data = s;
                        // 최종값 표시
                        isConsistent = false;
                        break;
                    }

                    // 해당 값이 있는데 그 값이 이미 최종 값이라면
                    if (next->data != "") {
                        isConsistent = false;
                        break;
                    }
                } else {
                    // 해당 값이 없다면
                    node *child = new node();
                    child->key = s[j];
                    if (j == s.size() - 1) {
                        // 근데 마지막 값에 도달했다면?
                        child->data = s;
                    }
                    next->children[s[j]] = *child;
                    next = &next->children[s[j]];
                    // 만들고 추가
                }
            }
        }

        if (isConsistent) {
            cout << "YES";
        } else
            cout << "NO";
        cout << "\n";
        delete root;
    }
    return 0;
}