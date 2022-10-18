#include <stdio.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    if ((argc > 2) && (argv[1][0] == 'f')) {
        for (int c = fgetc(stdin); c != EOF; c = fgetc(stdin))
            ;
    }
    else {
        for (int c = getc(stdin); c != EOF; c = getc(stdin))
            ;
    }
    return 0;
}
