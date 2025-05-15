#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>

#define FILENAME "log.txt"
#define MAX_FILE_SIZE 1024 

int main() {
    FILE *file;
    struct stat st;
    int roll;

    srand(time(NULL));

    file = fopen(FILENAME, "a");
    if (!file) {
        perror("cant open file");
        return 1;
    }

    while (1) {
        stat(FILENAME, &st);
        if (st.st_size >= MAX_FILE_SIZE) {
            printf("file size is too big (%ld bytes).\n", st.st_size);
            break;
        }

        roll = rand() % 6 + 1;
        fprintf(file, "rolled: %d\n", roll);
        fflush(file);
    }

    fclose(file);
    return 0;
}
