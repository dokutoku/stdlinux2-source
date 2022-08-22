/*
    tail2 -- simple tail command with no line length limitation
*/

#include <stdio.h>
#include <stdlib.h>

static void tail(FILE *f, int nlines);
static unsigned char *readline(FILE *f);

int
main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s n\n", argv[0]);
        exit(1);
    }
    tail(stdin, atoi(argv[1]));
    exit(0);
}

static void
tail(FILE *f, int nlines)
{
#define INC(ptrvar) do { \
    ptrvar++;                       \
    if (ptrvar >= ringbuf + nlines) \
        ptrvar = ringbuf;           \
} while (0)

    if (nlines == 0) return;

    unsigned char **ringbuf = calloc(nlines, sizeof(char*));
    if (ringbuf == NULL) exit(1);
    unsigned char **p = ringbuf;
    unsigned char *line;
    while (line = readline(f)) {
        if (*p)
            free(*p);
        *p = line;
        INC(p);
    }
    if (*p == NULL) p = ringbuf;
    for (int n = nlines; n > 0 && *p; n--) {
        printf("%s", *p);
        free(*p);
        INC(p);
    }
    free(ringbuf);
}

static unsigned char *
readline(FILE *f)
{
    size_t buflen = BUFSIZ;

    unsigned char *p = malloc(sizeof(char) * buflen);
    unsigned char *buf = p;
    if (buf == NULL) exit(1);
    for (;;) {
        int c = getc(f);
        if (c == EOF) {
            if (buf == p) {
                free(buf);
                return NULL;
            }
            break;
        }
        *p++ = c;
        if (p >= buf + buflen - 1) {
            buflen *= 2;
            buf = realloc(buf, buflen);
            if (buf == NULL) exit(1);
        }
        if (c == '\n') break;
    }
    *p++ = '\0';
    return buf;
}
