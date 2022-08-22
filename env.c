#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int
main(int argc, char *argv[])
{
    for (char **p = environ; *p != NULL; p++) {
        printf("%s\n", *p);
    }
    exit(0);
}
