#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void do_cat(FILE *f, int escape);

int main(int argc, char *argv[])
{
    int escape = 0;

    for (int opt = getopt(argc, argv, "e"); opt != -1; opt = getopt(argc, argv, "e")) {
        switch (opt) {
            case 'e':
                escape = 1;
                break;
            case '?':
                    fprintf(stderr, "Usage: %s [-e] [file...]\n", argv[0]);
                    exit(1);
            default:
                break;
        }
    }
    argc -= optind;
    argv += optind; // 配列ポインタの先頭をずらす
    if (argc == 0) {
        do_cat(stdin, escape);
    } else {
        for (int i = 0; i < argc; i++) {
            FILE *f = fopen(argv[i], "r");
            if (f == NULL) {
                perror(argv[i]);
                exit(1);
            }
            do_cat(f, escape);
            fclose(f);
        }
    }
    return 0;
}

static void do_cat(FILE *f, int escape) {
    if (escape != 0) {
        for (int c = fgetc(f); c != EOF; c = fgetc(f)) {
            switch (c) {
                case '\t':
                    if (fputs("\\t", stdout) == EOF) exit(1);
                    break;
                case '\n':
                    if (fputs("$\n", stdout) == EOF) exit(1);
                    break;
                default:
                    if (putchar(c) < 0) exit(1);
                    break;
            }
        }
    } else {
        for (int c = fgetc(f); c != EOF; c = fgetc(f)) {
            if (putchar(c) < 0) exit(1);
        }
    }
}
