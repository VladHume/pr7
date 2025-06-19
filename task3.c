#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s слово файл\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *pattern = argv[1];
    FILE *f = fopen(argv[2], "r");
    if (!f) { perror("fopen"); return EXIT_FAILURE; }

    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, f) != -1) {
        if (strstr(line, pattern))
            fputs(line, stdout);
    }

    free(line);
    fclose(f);
    return EXIT_SUCCESS;
}
