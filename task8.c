#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    DIR *d = opendir(".");
    struct dirent *e;
    char ans[4];

    if (!d) return EXIT_FAILURE;

    while ((e = readdir(d))) {
        if (strcmp(e->d_name, ".") == 0 || strcmp(e->d_name, "..") == 0)
            continue;
        printf("Delete file %s? (y/n/a — all): ", e->d_name);
        if (!fgets(ans, sizeof(ans), stdin)) break;
        if (ans[0] == 'a') break;
        if (ans[0] == 'y') {
            if (unlink(e->d_name) == 0)
                printf("Deleted\n");
            else
                perror("unlink");
        }
    }

    closedir(d);
    return EXIT_SUCCESS;
}
