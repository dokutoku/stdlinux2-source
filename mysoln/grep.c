#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>

static void do_grep(regex_t *pat, FILE *f);

int main(int argc, char const* argv[])
{
    if (argc < 2) {
        fputs("no pattern\n", stderr);
        return 1;
    }
    regex_t pat;
    int err = regcomp(&pat, argv[1], REG_EXTENDED | REG_NOSUB | REG_NEWLINE);
    if (err != 0) {
        char buf[1024];

        regerror(err, &pat, buf, sizeof buf);
        puts(buf);
        return 1;
    }
    if (argc == 2) {
        do_grep(&pat, stdin);
    } else {
        for (int i = 2; i < argc; i++) {
            FILE *f = fopen(argv[i], "r");
            if (f == NULL) {
                perror(argv[i]);
                return 1;
            }
            do_grep(&pat, f);
            fclose(f);
        }
    }
    regfree(&pat);
    return 0;
}

static void do_grep(regex_t *pat, FILE *src) {
    char buf[4096];

    while (fgets(buf, sizeof buf, src) != NULL) {
        if (regexec(pat, buf, 0, NULL, 0) == 0) {
            fputs(buf, stdout);
        }
    }
}
