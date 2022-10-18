#include <stdio.h>
#include <unistd.h>

int main(int argc, char const* argv[])
{
    if (argc < 2) {
        fprintf(stderr, "%s: no arguments\n", argv[0]);
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        if (unlink(argv[i]) < 0) {
            perror(argv[i]);
            return 1;
        }
    }
    return 0;
}
