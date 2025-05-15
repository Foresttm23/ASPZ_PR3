#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>

void handle_sigxcpu(int signum) {
    printf("\ncpu time ended. stopping...\n");
    exit(1);
}

void generate_nums(int count, int max) {
    int nums[max + 1];
    for (int i = 1; i <= max; i++) nums[i] = i;

    for (int i = 0; i < count; i++) {
        int temp = rand() % (max - i) + 1;
        printf("%d ", nums[temp]);
        nums[temp] = nums[max - i];
    }
    printf("\n");
}

void use_cpu() {
    unsigned long long i = 0;
    while (1) i++;
}

int main() {
    struct rlimit rl;
    rl.rlim_cur = 1;
    rl.rlim_max = 2;

    setrlimit(RLIMIT_CPU, &rl);

    signal(SIGXCPU, handle_sigxcpu);

    srand(time(NULL));
    printf("roll 7/49: ");
    generate_nums(7, 49);

    printf("roll 6/36: ");
    generate_nums(6, 36);

    use_cpu();

    return 0;
}
