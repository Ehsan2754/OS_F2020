#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    int fd = -1, parpid = getpid();
    char *zero;
    if ((fd = open(PATH, O_RDWR, 0)) == -1)
        err(1, "open");
    zero = (char *)mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_FILE | MAP_SHARED, fd, 0);
    if (zero == MAP_FAILED)
        errx(1, "either mmap");
    strcpy(zero, text);
    printf("PID %d:\t %s -> %s\n", parpid,PATH,zero);
    close(fd);
    return (EXIT_SUCCESS);
    return 0;
}
