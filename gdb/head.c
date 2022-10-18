#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#define _GNU_SOURCE
#include <getopt.h>

static void do_head(FILE *f, int nlines);

#define DEFAULT_N_LINES 10

static struct option longopts[] = {
    {"lines", required_argument, NULL, 'n'},
    {"help",  no_argument,       NULL, 'h'},
    {0, 0, 0, 0}
};

int
main(int argc, char *argv[])
{
    int nlines = DEFAULT_N_LINES;

    for (int opt = getopt_long(argc, argv, "n", longopts, NULL); opt != -1; opt = getopt_long(argc, argv, "n", longopts, NULL)) {
        switch (opt) {
        case 'n':
            nlines = atoi(optarg);
            break;
        case 'h':
            fprintf(stdout, "Usage: %s [-n LINES] [FILE ...]\n", argv[0]);
            return 0;
        case '?':
            fprintf(stderr, "%s: unknown option: -%c\n", argv[0], optopt);
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
do_head(FILE *f, int nlines)
{
    if (nlines == 0) return;
    for (int c = getc(f); c != EOF; c = getc(f)) {
        if (putchar(c) < 0) exit(1);
        if (c == '\n') {
            nlines--;
            if (nlines == 0)
                return;
        }
    }
}
