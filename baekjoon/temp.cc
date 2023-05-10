#include <bits/stdc++.h>

using namespace std;

void shiftRow(vector<vector<int>>& rc) {
    int h = rc.size();
    int w = rc[0].size();
    vector<int> temp(w);
    for(int j=0; j<w; j++) {
        temp[j] = rc[h-1][j];
    }
    for(int i=h-1; i>0; i--) {
        for(int j=0; j<w; j++) {
            rc[i][j] = rc[i-1][j];
        }
    }
    for(int j=0; j<w; j++) {
        rc[0][j] = temp[j];
    }
}

void rotate(vector<vector<int>>& rc) {
    int temp = rc[0][0];
    int h = rc.size();
    int w = rc[0].size();
    for(int i=1; i<h; i++) {
        rc[i-1][0] = rc[i][0];
    }
    for(int i=1; i<w; i++) {
        rc[h-1][i-1] = rc[h-1][i];
    }
    for(int i=h-1; i>0; --i) {
        rc[i][w-1] = rc[i-1][w-1];
    }
    for(int i=w-1; i>0; i--) {
        rc[0][i] = rc[0][i-1];
    }
    rc[0][1] = temp;
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    string before = "";
    int beforeCnt = 0;
    for(string operation : operations) {
        if(operation != before) {
            if(before == "Rotate") {
                for(int i=0; i<beforeCnt; i++) {
                    rotate(rc);
                }
            }
            else {
                for(int i=0; i<beforeCnt; i++) {
                    shiftRow(rc);
                }
            }
            beforeCnt = 1;
            before = operation;
        }
        else {
            beforeCnt++;
            if(before == "Rotate" && beforeCnt % ((rc.size() * rc[0].size()) - 1) == 0) {
                beforeCnt = 0;
            }
            else if(before == "ShiftRow" && beforeCnt % rc.size() == 0) {
                beforeCnt = 0;
            }
        }
    }

    if (before == "Rotate") {
        for (int i = 0; i < beforeCnt; i++) {
            rotate(rc);
        }
    } else {
        for (int i = 0; i < beforeCnt; i++) {
            shiftRow(rc);
        }
    }

    return rc;
}

void print(vector<vector<int>> arr) {
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    vector<vector<int>> arr(3, vector<int>(3));
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[0].size(); j++) {
            cin >> arr[i][j];
        }
    }
    rotate(arr);
    print(arr);
    shiftRow(arr);
    print(arr);
}