#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    char *path = getcwd(NULL, 0);
    if (path == NULL) {
        perror(path);
        exit(1);
    }
    puts(path);
    free(path);
    exit(0);
}
