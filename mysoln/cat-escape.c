#include <stdio.h>

int main(int argc, char const* argv[])
{
    for (int i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");
        if (f == NULL) {
            perror(argv[i]);
            return 1;
        }
        for (int c = fgetc(f); c != EOF; c = fgetc(f)) {
            if (c == '\t') {
                if (putchar('\\') < 0) return 1;
                if (putchar('t') < 0) return 1;
            } else if (c == '\n') {
                if (putchar('$') < 0) return 1;
                if (putchar('\n') < 0) return 1;
            } else if (putchar(c) < 0) return 1;
        }
        fclose(f);
    }
    return 0;
}
