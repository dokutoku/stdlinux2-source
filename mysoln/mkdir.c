#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char const* argv[])
{
    if (argc < 2) {
        fprintf(stderr, "%s: no arguments\n", argv[0]);
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        if (mkdir(argv[i], 0777) < 0) {
            perror(argv[i]);
            return 1;
        }
    }
    return 0;
}
