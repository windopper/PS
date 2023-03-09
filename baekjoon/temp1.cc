#include <bits/stdc++.h>

int main() {
    char buffer[256] = "15 12";
    int num_a;
    sscanf_s(buffer + 2, "%d", &num_a);
    printf("%d", num_a);
}