#include <stdio.h>

int main(int argc, char* argv[]) {
        if (argc < 2) {
                return 1;
        }

        FILE* fd = fopen(argv[1], "w");
        fclose(fd);
        return 0;
}
