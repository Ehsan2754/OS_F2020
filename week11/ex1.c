#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
#define PATH "./ex1.txt"
int main(int argc, char const *argv[])
{
    const char text[1000] = "This is a nice day";

    int fd = -1, tmp = -1, parpid = getpid(), len = strlen(text);
    char *zero;
    if ((tmp = open(PATH, O_RDWR)) == -1)
        err(1, "open %s",PATH);
    ftruncate(tmp,len);
    close(tmp);
    if ((fd = open(PATH, O_RDWR, 0)) == -1)
        err(1, "open %s",PATH);
    zero = (char *)mmap(NULL, len + 1, PROT_READ | PROT_WRITE, MAP_FILE | MAP_SHARED, fd, 0);
    if (zero == MAP_FAILED)
        errx(1, "either mmap");
    strcpy(zero, text);
    printf("PID %d:\t %s -> %s\n", parpid, PATH, zero);
    close(fd);
    return (EXIT_SUCCESS);
}
