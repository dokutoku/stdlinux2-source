#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const* argv[])
{
    for (int i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");
        if (f == NULL) {
            perror(argv[i]);
            exit(1);
        }
        for (int c = fgetc(f); c != EOF; c = fgetc(f)) {
            if (putchar(c) < 0) exit(1);
        }
        fclose(f);
    }
    exit(0);
}
