#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char buf[512];

    if (!(fp = popen("rwho | more", "r"))) {
        perror("popen");
        return EXIT_FAILURE;
    }

    while (fgets(buf, sizeof(buf), fp)) {
        fputs(buf, stdout);
    }

    pclose(fp);
    return EXIT_SUCCESS;
}
