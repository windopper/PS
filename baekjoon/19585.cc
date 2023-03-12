#include <bits/stdc++.h>

using namespace std;

struct Trie {
    char c;
    bool isColor = false;
    bool isNickName = false;
    map<char, Trie*> arr;

    Trie* findOrCreate(char x) {
        if(this->arr.find(x) != this->arr.end()) return this->arr[x];

        Trie* newTrie = new Trie();
        newTrie->c = x;
        this->arr[x] = newTrie;
        return newTrie;
    }

    Trie* find(char x) {
        if(this->arr.find(x) != this->arr.end()) return this->arr[x];
        return nullptr;
    }

    bool hasNext() {
        return this->arr.size() >= 1;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int C, N;
    cin >> C >> N;

    Trie* root = new Trie();

    Trie* cur = root;

    for(int i=0; i<C; i++) {
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++) {
            Trie* trie = cur->findOrCreate(s[j]);
            if(j == s.size() - 1) trie->isColor = true;
            cur = trie;
        }
        cur = root;
    }


    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++) {
            Trie* trie = cur->findOrCreate(s[j]);
            if(j == s.size() - 1) trie->isNickName = true;
            cur = trie;
        }
        cur = root;
    }
    
    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++) {
        cur = root;
        Trie* other = root;
        stack<int> st;
        string s;
        cin >> s;
        bool cont = false;
        bool isColor = false;
        bool isNickName = false;
        for(int j=0; j<s.size(); j++) {
            cur = cur->find(s[j]);

            if(cur == nullptr) {
                break;
            }

            if(!isColor && cur->isColor) {
                // 처음 색깔을 보면
                isColor = true;
                if(!cur->hasNext()) {
                    root = cur;
                    cont = false;
                }
                else {
                    cont = true;
                }
                continue;
            }
            
            if(isColor && cur->isColor) {
                // 색깔이 있는데 또 색깔
                if(!cur->hasNext()) {
                    root = cur;
                    cont = false;
                }
                else {
                    cont = true;
                }
                continue;
            }

            if(isColor && cur->isNickName) {
                // 색깔이 있을 때 닉네임
                if(cont) {
                    isColor = false;
                    isNickName = true;
                }
                else {
                    isNickName = true;
                }

                if(!cur->hasNext()) {
                    cont = false;
                    root = cur;
                }
                cont = true;
            }

            if(isNickName && cur->isColor) {
                if(cont) {
                    isColor = true;
                    isNickName = false;
                }
                else {
                    isColor = true;
                }

                if(!cur->hasNext()) {
                    cont = false;
                    root = cur;
                }
                cont = true;
            }
        }

        if(!st.empty() && st.top() == 1) {
            st.pop();
            if(!st.empty() && st.top() == 0) {
                cout << "Yes" << "\n";
                continue;
            }
        }

        cout << "No" << "\n";

    }
}