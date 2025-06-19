#include <stdio.h>
#include <sys/time.h>

int main(void) {
    struct timeval t0, t1;
    gettimeofday(&t0, NULL);
    for (volatile int i = 0; i < 10000000; i++);
    
    gettimeofday(&t1, NULL);
    long ms = (t1.tv_sec - t0.tv_sec) * 1000 +
              (t1.tv_usec - t0.tv_usec) / 1000;
    printf("Time: %ld мс\n", ms);
    return 0;
}
