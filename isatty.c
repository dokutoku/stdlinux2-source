#include <stdio.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    printf("stdin:  %d\n", isatty(0));
    printf("stdout: %d\n", isatty(1));
    printf("stderr: %d\n", isatty(2));
    return 0;
}
