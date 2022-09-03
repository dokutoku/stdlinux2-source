#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

int
main(int argc, char *argv[])
{
    char *fmtchars = "aAbBcCdDeFgGhHIjklmMnOpPrRsStTuUVwWxXyYzZ+";
    char *opt_E = "cCxXyY";
    char *opt_O = "deHImMSuUvwWy";

    setlocale(LC_ALL, "");
    time_t t;
    time(&t);
    struct tm *tm = localtime(&t);
    for (char *p = fmtchars; *p != '\0'; p++) {
        char fmt[16];
        char buf[256];

        printf("%%%c=", *p);
        fmt[0] = '"';
        fmt[1] = '%';
        fmt[2] = *p;
        fmt[3] = '"';
        fmt[4] = '\0';
        if (strftime(buf, sizeof buf, fmt, tm) == 0)
            puts("FAILED");
        else
            puts(buf);

        if (strchr(opt_E, *p) != NULL) {
            printf("%%E%c=", *p);
            fmt[0] = '"';
            fmt[1] = '%';
            fmt[2] = 'E';
            fmt[3] = *p;
            fmt[4] = '"';
            fmt[5] = '\0';
            if (strftime(buf, sizeof buf, fmt, tm) == 0)
                puts("FAILED");
            else
                puts(buf);
        }
        if (strchr(opt_O, *p) != NULL) {
            printf("%%O%c=", *p);
            fmt[0] = '"';
            fmt[1] = '%';
            fmt[2] = 'O';
            fmt[3] = *p;
            fmt[4] = '"';
            fmt[5] = '\0';
            if (strftime(buf, sizeof buf, fmt, tm) == 0)
                puts("FAILED");
            else
                puts(buf);
        }
    }
    exit(0);
}
