#include <stdio.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "%s: wrong number of arguments\n", argv[0]);
        return 1;
    }
    if (symlink(argv[1], argv[2]) < 0) {
        perror(argv[1]);
        return 1;
    }
    return 0;
}
