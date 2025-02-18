/*
    Usage: chown <user> <file>...

    <user> must be a user name.  User ID is not supported.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>

static uid_t get_user_id(char *user);

int
main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "no user name given\n");
        return 1;
    }
    uid_t uid = get_user_id(argv[1]);
    for (int i = 2; i < argc; i++) {
        if (chown(argv[i], uid, -1) < 0) {
            perror(argv[i]);
        }
    }
    return 1;
}

static uid_t
get_user_id(char *user)
{
    struct passwd *pw = getpwnam(user);
    if (pw == NULL) {
        fprintf(stderr, "no such user: %s\n", user);
        exit(1);
    }
    return pw->pw_uid;
}
