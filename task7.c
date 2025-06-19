#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main(void) {
    DIR *d = opendir(".");
    struct dirent *e;
    struct stat st;
    char ans[4];

    if (!d) return EXIT_FAILURE;

    while ((e = readdir(d))) {
        size_t len = strlen(e->d_name);
        if (len > 2 && strcmp(e->d_name + len - 2, ".c") == 0) {
            stat(e->d_name, &st);
            printf("Файл %s, поточні права: %o. Додати r іншим? (y/n): ", 
                   e->d_name, st.st_mode & 0777);
            if (fgets(ans, sizeof(ans), stdin) && ans[0]=='y') {
                chmod(e->d_name, st.st_mode | S_IROTH);
                printf("Права змінено.\n");
            }
        }
    }
    closedir(d);
    return EXIT_SUCCESS;
}
