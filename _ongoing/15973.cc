#include <iostream>
#include <string>
using namespace std;
long long px1, px2, py1, py2, qx1, qx2, qy1, qy2;

string status() {
    if(py1 > qy2 || py2 < qy1 || px1 > qx2 || px2 < qx1) {
        return "NULL";
    }
    if((px2 == qx1 && py2 == qy1) || (px2 == qx1 && py1 == qy2) ||
        (px1 == qx2 && py1 == qy2) || (px1 == qx2 && py2 == qy1)) {
            return "POINT";
    }
    if(((px2 == qx1 && ((qy1 >= py1 && qy1 <= py2) || (qy2 >= py1 && qy2 <= py2)))
        || (px1 == qx2 && ((qy2 >= py1 && qy2 <= py2) || (qy1 >= py1 && qy2 <= py2)))
        || (py2 == qy1 && ((qx1 >= px1 && qx1 <= px2) || (qx2 >= px1 && qx2 <= px2)))
        || (py1 == qy2 && ((qx1 >= px1 && qx1 <= px2) || (qx2 >= px1 && qx2 <= px2))))) {
            return "LINE";
    }
    return "FACE";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> px1 >> py1 >> px2 >> py2;
    cin >> qx1 >> qy1 >> qx2 >> qy2;
    if (px1 > px2 || py1 > py2) {
        swap(px1, px2);
        swap(py1, py2);
    }
    if (qx1 > qx2 || qy1 > qy2) {
        swap(qx1, qx2);
        swap(qy1, qy2);
    }
    cout << status();
    return 0;
}