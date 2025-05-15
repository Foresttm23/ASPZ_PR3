#include <stdio.h>

void recursive(int n) {
    char buffer[1024]; 
    printf("repeat: %d\n", n);
    recursive(n + 1);
}

int main() {
    recursive(1);
    return 0;
}
