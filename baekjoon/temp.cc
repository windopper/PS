
#include <bits/stdc++.h>

using namespace std;

int global = 1;

void multiply_numbers(int a, int b) {
    int temp = a * b;
    global = 2;
}

int main() {
    multiply_numbers(2, 3);   
}