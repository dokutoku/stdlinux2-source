#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

static char * user_name(uid_t id);
static char * group_name(gid_t id);

int
main(int argc, char *argv[])
{
    uid_t u = getuid();
    printf("uid=%d", u);
    char *name;
    if ((name = user_name(u)) != NULL) {
        printf("(%s)", name);
    }

    gid_t g = getgid();
    printf(" gid=%d", g);
    if ((name = group_name(g)) != NULL) {
        printf("(%s)", name);
    }

    long group_max = sysconf(_SC_NGROUPS_MAX);
    gid_t *buf = malloc(sizeof(gid_t) * group_max);
    if (buf == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }
    int n = getgroups(group_max, buf);
    if (n < 0) {
        perror("getgroups");
        exit(1);
    }
    printf(" groups=");
    char *comma = "";
    for (long i = 0; i < n; i++) {
        printf("%s%d(%s)", comma, buf[i], group_name(buf[i]));
        comma = ",";
    }
    printf("\n");

    exit(0);
}

static char *
user_name(uid_t id)
{
    struct passwd *pw = getpwuid(id);
    if (pw == NULL) return NULL;
    return pw->pw_name;
}

static char *
group_name(gid_t id)
{
    struct group *gr = getgrgid(id);
    if (gr == NULL) return NULL;
    return gr->gr_name;
}
