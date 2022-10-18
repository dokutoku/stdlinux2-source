#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDONLY);
    unsigned char buf[BUFSIZ];
    for (;;) {
        int n = read(fd, buf, BUFSIZ);
        if (n == 0) break;
        n = write(STDOUT_FILENO, buf, n);
    }
    close(fd);
    return 0;
}
