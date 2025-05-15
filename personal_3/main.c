#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t size = 1024 * 1024 * 500; // 500 mb

    char *memory = malloc(size);
    if (memory == NULL) {
        perror("memory alloc failed");
        return 1;
    }

    for (size_t i = 0; i < size; i += 4096) {
        memory[i] = 'a';
    }

    printf("memory filled\n");

    free(memory);
    return 0;
}
