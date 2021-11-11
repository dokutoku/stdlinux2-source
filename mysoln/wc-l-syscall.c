#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void wc(const char *path);
static void die(const char *s);

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "%s: file name not given\n", argv[0]);
        exit(1);
    }
    for (int i = 1; i < argc; i++) {
        wc(argv[i]);
    }
    exit(0);
}

#define BUFFER_SIZE 2048

static void wc(const char *path) {
    int fd;
    int n;

    fd = open(path, O_RDONLY);
    if (fd < 0) die(path);
    unsigned long count = 0;
    for (;;) {
        unsigned char buf[BUFFER_SIZE];
        n = read(fd, buf, sizeof buf);
        if (n < 0) die(path);
        if (n == 0) break;
        for (unsigned long i = 0; i < n; i++) {
            if (buf[i] == '\n') {
                count++;
                // printf("%lu\n", count);
            }
        }
    }
    printf(" %lu %s\n", count, path);
    if (close(fd) < 0) die(path);
}

static void die(const char *s) {
    perror(s);
    exit(1);
}
