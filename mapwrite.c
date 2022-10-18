#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define DATAFILE "mapwrite.data"

int
main(int argc, char *argv[])
{
    int len = 3;

    /* prepare data file */
    unlink(DATAFILE);   /* ignore error */
    int fd = open(DATAFILE, O_WRONLY|O_CREAT, 0666);
    if (fd < 0) {
        perror(DATAFILE);
        return 1;
    }
    write(fd, "NO\n", 3);
    close(fd);

    /* write by mmap */
    fd = open(DATAFILE, O_RDWR);
    if (fd < 0) {
        perror(DATAFILE);
        return 1;
    }
    char *ptr = (char*)mmap(0, len, PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == NULL) {
        perror("mmap(2)");
        return 1;
    }
    close(fd);
    ptr[0] = 'O';
    ptr[1] = 'K';
    ptr[2] = '\n';
    munmap(ptr, len);

    /* cat it */
    system("cat " DATAFILE);

    return 0;
}
