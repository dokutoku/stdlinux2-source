#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void
showsig(int sig)
{
    printf("signal=%d\n", sig);
}

int
main(int argc, char *argv[])
{
    signal(SIGINT, showsig);
    pause();
    pause(); // OSによっては2回目の SIGINT で showsig が呼ばれない(?)
    exit(0);
}
