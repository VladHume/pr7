#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void walk(const char *path) {
    DIR *d = opendir(path);
    struct dirent *e;
    char full[PATH_MAX];
    if (!d) return;

    while ((e = readdir(d))) {
        if (strcmp(e->d_name, ".")==0 || strcmp(e->d_name, "..")==0) continue;
        snprintf(full, sizeof(full), "%s/%s", path, e->d_name);
        printf("%s\n", full);
        struct stat st;
        if (!stat(full, &st) && S_ISDIR(st.st_mode))
            walk(full);
    }

    closedir(d);
}

int main(void) {
    walk(".");
    return EXIT_SUCCESS;
}
