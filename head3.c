#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void do_head(FILE *f, long nlines);

#define DEFAULT_N_LINES 10

int
main(int argc, char *argv[])
{
    long nlines = DEFAULT_N_LINES;

    for (int opt = getopt(argc, argv, "n:"); opt != -1; opt = getopt(argc, argv, "n:")) {
        switch (opt) {
        case 'n':
            nlines = atol(optarg);
            break;
        case '?':
            fprintf(stderr, "Usage: %s [-n LINES] [file...]\n", argv[0]);
            return 1;
        default:
            break;
        }
    }
    if (optind == argc) {
        do_head(stdin, nlines);
    } else {
        for (int i = optind; i < argc; i++) {
            FILE *f = fopen(argv[i], "r");
            if (f == NULL) {
                perror(argv[i]);
                return 1;
            }
            do_head(f, nlines);
            fclose(f);
        }
    }
    return 0;
}

static void
do_head(FILE *f, long nlines)
{
    if (nlines <= 0) return;
    for (int c = getc(f); c != EOF; c = getc(f)) {
        if (putchar(c) < 0) exit(1);
        if (c == '\n') {
            nlines--;
            if (nlines == 0) return;
        }
    }
}
