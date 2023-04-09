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

    // color
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

    // nickname
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        for(int j=s.size()-1; j>=0; j--) {
            Trie* trie = cur->findOrCreate(s[j]);
            if(j == 0) trie->isNickName = true;
            cur = trie;
        }
        cur = root;
    }
    
    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++) {
        string s;
        cin >> s;
        vector<int> colorDoneLoc;
        vector<int> nickNameDoneLoc;
        Trie* color = root;
        Trie* nickName = root;
        for(int i=0; i<s.size(); i++) {
            color = color->find(s[i]);
            if(color == nullptr) break;
            if(color->isColor) colorDoneLoc.push_back(i);
        }

        for(int i=s.size()-1; i>=0; --i) {
            nickName = nickName->find(s[i]);
            if(nickName == nullptr) break;
            if(nickName->isNickName) nickNameDoneLoc.push_back(i);
        }
        bool done = false;
        for(int i : colorDoneLoc) {
            for(int j : nickNameDoneLoc) {
                if(i + 1 == j) {
                    done = true;
                    break;
                }
            }
            if(done) break;
        }

        if(done) {
            cout << "Yes";
        } else cout << "No";

        cout << "\n";

    }
}