#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#define PATH "./ex1.txt"
#define TARGET "./ex1.memcpy.txt"
int main(int argc, char const *argv[])
{
    struct stat buffer_0;
    int fd = -1, ft = -1, parpid = getpid();
    char *zero, *one;
    if ((fd = open(PATH, O_RDWR, 0)) == -1)
        err(1, "open %s",PATH);
    fstat(fd, &buffer_0);
    zero = mmap(NULL, buffer_0.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (zero == MAP_FAILED)
        errx(1, "either mmap");
    if ((ft = open(TARGET, O_RDWR, 0)) == -1)
        err(1, "open %s",TARGET);
    ftruncate(ft, buffer_0.st_size);
    one = mmap(NULL, buffer_0.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, ft, 0);
    memcpy(one, zero, buffer_0.st_size);
    printf("PID %d:\t ' %s -> %s ' :=: %s\n", parpid,PATH,TARGET,zero);
    close(fd);
    close(ft);
    return (EXIT_SUCCESS);
}
