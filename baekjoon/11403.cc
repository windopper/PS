#include <iostream>

using namespace std;

int N;

int main() {
    
    cin >> N;

    int arr[N][N];

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }

    for(int m=0; m<N; m++) {
        for(int s=0; s<N; s++) {
            for(int e=0; e<N; e++) {
                if (arr[s][e] == 0 && arr[s][m] == 1 && arr[m][e] == 1) {
                    arr[s][e] = 1;
                }
            }
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}