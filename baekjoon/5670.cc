#include <bits/stdc++.h>
using namespace std;

struct Trie {
    char c;
    map<char, Trie*> nxt;
    int size = 0;
    bool done = false;
    Trie(char c_): c(c_) {}
    Trie() {}

    Trie* find(char c) {
        if(nxt[c]) return nxt[c];
        return nullptr;
    }

    Trie* findOrCreate(char c) {
        if(nxt[c]) return nxt[c];
        Trie* trie = new Trie(c);
        this->nxt[c] = trie;
        ++this->size;
        return trie;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed, cout.precision(2);
    int t;
    while(cin >> t) {

        Trie* head = new Trie();
        Trie* cur = head;

        vector<string> arr;

        for(int i=0; i<t; i++) {
            cur = head;
            string s;
            cin >> s;
            arr.push_back(s);
            for(int j=0; j<s.size(); j++) {
                cur = cur->findOrCreate(s[j]);
                if(j == s.size() - 1) cur->done = true;
            }
        }

        double avg = 0;
        for(string s : arr) {
            int cnt = 0;
            cur = head;
            for(int i=0; i<s.size(); i++) {
                if(cur->size > 1 || cur->done || i == 0) {
                    ++cnt;
                }
                cur = cur->find(s[i]);
            }
            //cout << cnt << "\n";
            avg += cnt;
        }
        
        avg /= arr.size();
        avg = round(avg * 100) / 100;

        cout << avg << "\n";
    }
}