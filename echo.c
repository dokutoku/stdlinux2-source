#include <stdio.h>

int
main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        printf("%s%s", (i==1?"":" "), argv[i]);
    }
    putchar('\n');
    return 0;
}
