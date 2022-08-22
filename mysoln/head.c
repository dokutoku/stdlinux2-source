#include <stdio.h>
#include <stdlib.h>

static void do_head(FILE *f, long nlines);

#define _GNU_SOURCE
#include <getopt.h>

#define DEFAULT_N_LINES 10

static struct option longopts[] = {
    {"lines", required_argument, NULL, 'n'},
    {"help", no_argument,        NULL, 'h'},
    {0,0,0,0}
};

int main(int argc, char* argv[])
{
    int opt;
    long nlines = DEFAULT_N_LINES;

    while ((opt = getopt_long(argc, argv, "n:", longopts, NULL)) != -1) {
        switch (opt) {
            case 'n':
                nlines = atol(optarg);
                break;
            case 'h':
                fprintf(stdout, "Usage: %s [-n LINES] [FILE ...]\n", argv[0]);
                exit(0);
            case '?':
                fprintf(stderr, "Usage: %s [-n LINES] [FILE ...]\n", argv[0]);
                exit(1);
        }
    }

    if (optind == argc) {
        do_head(stdin, nlines);
    } else {
        for (int i = optind; i < argc; i++) {
            FILE *f = fopen(argv[i], "r");
            if (!f) {
                perror(argv[i]);
                exit(1);
            }
            do_head(f, nlines);
            fclose(f);
        }
    }

    return 0;
}

static void do_head(FILE *f, long nlines) {
    if (nlines <= 0) return;
    int c;
    while ((c = getc(f)) != EOF) {
        if (putchar(c) < 0) exit(1);
        if (c == '\n') {
            nlines--;
            if (nlines == 0) return;
        }
    }
}
