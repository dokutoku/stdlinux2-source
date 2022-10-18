#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define INIT_BUFSIZE 1024

char*
my_getcwd(void)
{
    size_t size = INIT_BUFSIZE;

    char *buf = malloc(size);
    if (buf == NULL) return NULL;
    for (;;) {
        errno = 0;
        if (getcwd(buf, size) != NULL)
            return buf;
        if (errno != ERANGE) break;
        size *= 2;
        char *tmp = realloc(buf, size);
        if (tmp == NULL) break;
        buf = tmp;
    }
    free(buf);
    return NULL;
}

int
main(int argc, char *argv[])
{
    char *path = my_getcwd();
    if (path == NULL) {
        perror("getcwd");
        return 1;
    }
    puts(path);
    free(path);
    return 0;
}
