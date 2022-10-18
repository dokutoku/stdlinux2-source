#include <stdio.h>

int
main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");
        if (f == NULL) {
            perror(argv[i]);
            return 1;
        }
        for (int c = fgetc(f); c != EOF; c = fgetc(f)) {
            if (putchar(c) < 0) return 1;
        }
        fclose(f);
    }
    return 0;
}
