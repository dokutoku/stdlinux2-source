#include <stdio.h>

extern int a(void);
extern int b(void);

int
main(int argc, char **argv)
{
    a();
    b();
    return 0;
}
