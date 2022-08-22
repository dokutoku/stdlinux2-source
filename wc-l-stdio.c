#include <stdio.h>
#include <stdlib.h>

static void do_wc_l(FILE *f);

int
main(int argc, char *argv[])
{
    if (argc == 1) {
        do_wc_l(stdin);
    } else {
        for (int i = 1; i < argc; i++) {
            FILE *f = fopen(argv[i], "r");
            if (!f) {
                perror(argv[i]);
                exit(1);
            }
            do_wc_l(f);
            fclose(f);
        }
    }
    exit(0);
}

static void
do_wc_l(FILE *f)
{
    unsigned long n = 0;
    int c;
    int prev = '\n';   /* '\n' is for empty file */
    while ((c = getc(f)) != EOF) {
        if (c == '\n') {
            n++;
        }
        prev = c;
    }
    if (prev != '\n') {
        /* missing '\n' at the end of file */
        n++;
    }
    printf("%lu\n", n);
}
