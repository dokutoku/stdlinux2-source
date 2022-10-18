#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int
main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "no argument\n");
        return 1;
    }
    struct passwd *pw = getpwnam(argv[1]);
    if (pw == NULL) {
        perror(argv[1]);
        return 1;
    }
    printf("id=%d\n", pw->pw_uid);
    return 0;
}
