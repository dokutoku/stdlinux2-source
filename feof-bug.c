#include <stdio.h>

#define MAXLINE 16

int
main(int argc, char *argv[])
{
    FILE *f = stdin;
    char buf[MAXLINE + 1];

    while (feof(f) == 0) {
        fgets(buf, MAXLINE, f);
        fputs(buf, stdout);
    }
    return 0;
}
