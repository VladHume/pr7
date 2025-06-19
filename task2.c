#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>

void print_perms(mode_t m) {
    char buf[11] = "----------";
    buf[0] = S_ISDIR(m) ? 'd' : '-';
    buf[1] = m & S_IRUSR ? 'r' : '-';
    buf[2] = m & S_IWUSR ? 'w' : '-';
    buf[3] = m & S_IXUSR ? 'x' : '-';
    buf[4] = m & S_IRGRP ? 'r' : '-';
    buf[5] = m & S_IWGRP ? 'w' : '-';
    buf[6] = m & S_IXGRP ? 'x' : '-';
    buf[7] = m & S_IROTH ? 'r' : '-';
    buf[8] = m & S_IWOTH ? 'w' : '-';
    buf[9] = m & S_IXOTH ? 'x' : '-';
    printf("%s", buf);
}

int main(void) {
    DIR *d = opendir(".");
    struct dirent *e;
    struct stat st;
    char timestr[64];
    
    if (!d) { perror("opendir"); return EXIT_FAILURE; }
    
    while ((e = readdir(d))) {
        if (stat(e->d_name, &st) == -1) continue;

        print_perms(st.st_mode);
        printf(" %2ld", st.st_nlink);

        struct passwd *pw = getpwuid(st.st_uid);
        struct group *gr = getgrgid(st.st_gid);
        printf(" %s %s", pw ? pw->pw_name : "", gr ? gr->gr_name : "");
        printf(" %8lld", (long long)st.st_size);

        strftime(timestr, sizeof(timestr), "%b %e %H:%M", localtime(&st.st_mtime));
        printf(" %s %s\n", timestr, e->d_name);
    }

    closedir(d);
    return EXIT_SUCCESS;
}
