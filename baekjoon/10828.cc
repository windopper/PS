#include <bits/stdc++.h>
using namespace std;

class my_stack {
    int arr[10000];
    int last;
    public:
    my_stack() {
        last = -1;
    }
    void push(int x) {
        arr[++last] = x;
    }
    int pop() {
        if(empty()) return -1;
        return arr[last--];
    }
    int size() {
        return last + 1;
    }
    bool empty() {
        return last == -1 ? 1 : 0;
    }
    int top() {
        if(empty()) return -1;
        return arr[last];
    }

};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    my_stack s;
    for(int i=0; i<N; i++) {
        string cmd;
        int j;
        cin >> cmd;
        if(cmd == "push") {
            cin >> j;
            s.push(j);
        }
        else if(cmd == "pop") {
            cout << s.pop() << "\n";
        }
        else if(cmd == "size") {
            cout << s.size() << "\n";
        }
        else if(cmd == "empty") {
            cout << s.empty() << "\n";
        }
        else if(cmd == "top") {
            cout << s.top() << "\n";
        }
    }
}