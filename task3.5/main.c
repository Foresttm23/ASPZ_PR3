#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("need two args\n");
        return 1;
    }

    FILE *src = fopen(argv[1], "r");
    if (!src) {
        printf("cant open %s for reading\n", argv[1]);
        return 1;
    }

    FILE *dest = fopen(argv[2], "w");
    if (!dest) {
        printf("cant open %s for writing\n", argv[2]);
        fclose(src);
        return 1;
    }

    char buffer[1024];
    size_t bt;

    while ((bt = fread(buffer, 1, sizeof(buffer), src)) > 0) {

        fwrite(buffer, 1, bt, dest);
        printf("file size exceeded; stopping...\n");

    }

    fclose(src);
    fclose(dest);
    return 0;
}
