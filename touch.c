/*
    Simple touch(1) command.
    This program does not create file, just update atime/mtime.
*/

#include <stdio.h>
#include <sys/types.h>
#include <utime.h>

int
main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++) {
        if (utime(argv[i], NULL) < 0) {
            perror(argv[i]);
            /* We do not exit here...
             * return 1;
             */
        }
    }
    return 0;
}
