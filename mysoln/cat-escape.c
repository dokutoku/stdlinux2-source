#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const* argv[])
{
    for (int i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");
        if (!f) {
            perror(argv[i]);
            exit(1);
        }
        int c;
        while ((c = fgetc(f)) != EOF) {
            if (c == '\t') {
                if (putchar('\\') < 0) exit(1);
                if (putchar('t') < 0) exit(1);
            } else if (c == '\n') {
                if (putchar('$') < 0) exit(1);
                if (putchar('\n') < 0) exit(1);
            } else if (putchar(c) < 0) exit(1);
        }
        fclose(f);
    }
    exit(0);
}
