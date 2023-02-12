#include <iostream>

using namespace std;

int N;

int main() {
    
    cin >> N;

    int height[N][N];

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> height[i][j];
        }
    }

    for(int m=0; m<N; m++) {
        for(int s=0; s<N; s++) {
            for(int e=0; e<N; e++) {
                if (height[s][e] == 0 && height[s][m] == 1 && height[m][e] == 1) {
                    height[s][e] = 1;
                }
            }
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << height[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}