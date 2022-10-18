#include <stdio.h>
#include <math.h>
#include <dlfcn.h>

typedef double (*mathfunc_t)(double);

int
main(int argc, char *argv[])
{
    void *libm = dlopen("libm.so", RTLD_NOW);
    if (libm == NULL) {
        fprintf(stderr, "dlopen failed");
        return 1;
    }
    mathfunc_t sin = (mathfunc_t)dlsym(libm, "sin");
    double result = sin(0.5);
    printf("sin(0.5)=%g\n", result);
    return 0;
}
