#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double rnd01(void) {
    return rand() / (RAND_MAX + 1.0);
}

double rnd_n(double n) {
    return rnd01() * n;
}

int main(void) {
    srand(time(NULL) ^ getpid());

    printf("0..1: %f\n", rnd01());
    printf("0..n: %f\n", rnd_n(5.5)); // приклад
    return 0;
}
