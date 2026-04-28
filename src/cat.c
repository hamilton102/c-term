#include <stdio.h>

#define INPUT_BUF 256

/* flags */

void cat_int(char* input);
int cat_nonint(FILE* fd, char* input);
// void char_replace(char* input, char left, char* right);

int main(int argc, char* argv[])
{
        if (argc <= 0) return 1;
        char input[INPUT_BUF];
        if (argc == 1)
        {
                cat_int(input);
                return 0;
        }

        /* usage: cat <file> [args] */
        FILE* fd = fopen(argv[1], "r");
        if (cat_nonint(fd, input) != 0)
        {
                fclose(fd);
                return 1;
        }
        fclose(fd);
        return 0;
}

void cat_int(char* input)
{
        while(fgets(input, INPUT_BUF, stdin))
        {
                printf("%s", input);
        }
}

/* callee is responsible for free */
int cat_nonint(FILE* fd, char* input)
{
        if (!fd) return 1;
        while(fgets(input, INPUT_BUF, fd))
        {
                printf("%s", input);
        }
        return 0;
}
