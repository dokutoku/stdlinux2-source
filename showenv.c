#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        char *val = getenv(argv[i]);
        if (val != NULL) printf("%s\n", val);
    }
    return 0;
}
