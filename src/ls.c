#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

#define BUF_SIZ 256

void open(const char* name);
const char* format_strtime(const __time_t t);

int main(int argc, char* argv[]) {
        if (argc < 2) {
                fprintf(stderr, "Usage: ./ls [dir]");
                exit(1);
        } else {
                open(argv[1]);
        }
        return 0;
}

void open(const char* name) {
        DIR* dir;
        dir = opendir(name);
        struct stat file_info;

        if (dir == NULL) {
                perror("Can't open dir!");
                return;
        }

        struct dirent* i;

        while ((i = readdir(dir))) {
                if (stat(i->d_name, &file_info) == 0) {
                        printf("%ld\t", file_info.st_size);
                        // ctime includes \n
                        printf("%s\t", format_strtime(file_info.st_mtime));
                        printf("%s\n", i->d_name);
                }
        }

        closedir(dir);
        return;
}

const char* format_strtime(const __time_t t) {
        if (!t)
                return NULL;
        char* time_buf = malloc((sizeof(char*) * BUF_SIZ));
        struct tm time;

        localtime_r(&t, &time);

        strftime(time_buf, BUF_SIZ, "%d %m %H:%M:%S %Y", &time);
        return time_buf;
}
