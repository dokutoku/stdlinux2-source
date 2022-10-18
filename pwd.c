#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int
main(int argc, char *argv[])
{
    char buf[PATH_MAX];

    if (getcwd(buf, PATH_MAX) == NULL) {
        perror("getcwd");
        return 1;
    }
    puts(buf);
    return 0;
}
