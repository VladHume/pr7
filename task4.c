#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s file [file2 ...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");
        if (!f) { perror(argv[i]); continue; }

        char buf[512];
        int count = 0;
        while (fgets(buf, sizeof(buf), f)) {
            fputs(buf, stdout);
            if (++count == 20) {
                printf("-- More? (press Enter)");
                getchar();
                count = 0;
            }
        }

        fclose(f);
    }

    return EXIT_SUCCESS;
}
