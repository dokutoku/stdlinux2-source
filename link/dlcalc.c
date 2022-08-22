#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <dlfcn.h>

typedef double (*mathfunc_t)(double);

int
main(int argc, char *argv[])
{
    void *libm = dlopen("libm.so", RTLD_NOW);
    if (!libm) {
        fprintf(stderr, "dlopen failed");
        exit(1);
    }
    mathfunc_t sin = (mathfunc_t)dlsym(libm, "sin");
    double result = sin(0.5);
    printf("sin(0.5)=%g\n", result);
    exit(0);
}
