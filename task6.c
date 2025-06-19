#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int cmpstr(const void *a, const void *b) {
    return strcmp(*(char * const*)a, *(char * const*)b);
}

int main(void) {
    DIR *d = opendir(".");
    struct dirent *e;
    char **names = NULL;
    size_t n = 0;

    if (!d) { perror("opendir"); return EXIT_FAILURE; }

    while ((e = readdir(d))) {
        struct stat st;
        if (stat(e->d_name, &st) == 0 && S_ISDIR(st.st_mode)) {
            names = realloc(names, (n+1)*sizeof(*names));
            names[n++] = strdup(e->d_name);
        }
    }
    closedir(d);

    qsort(names, n, sizeof(*names), cmpstr);

    for (size_t i = 0; i < n; i++) {
        printf("%s\n", names[i]);
        free(names[i]);
    }
    free(names);
    return EXIT_SUCCESS;
}
