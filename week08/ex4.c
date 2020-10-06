#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <bits/types.h>
#define SIZE 10
#define MEGABYTE 1000000
#define INIT_VAL 0
int main(int argc, char const *argv[])
{
    printf("##########################################################################\n");
    printf("##################AHURATUS MEM ALLOCATOR#########WEEK08###################\n");
    printf("##############EHSAN SHAGHAEI#################OS-FALL2020##################\n");
    printf("##########################################################################\n");
    struct rusage data;
    for (int i = 0; i < 10; i++)
    {
        memset(calloc(SIZE * MEGABYTE, 1), INIT_VAL, SIZE * MEGABYTE);
        printf(">> MEM ALLOCATOR: 10MB were allocated!\n"); 
        getrusage(0, &data);
        printf("|USER    \t|PROCESS|TIME   |MAX RSS|IX RSS |ID RSS |IS RSS |IDS RSS|\n");
        printf("|ahuratus\t|ex4\t|%ld \t|%ld\t|%ld\t|%ld\t|%ld\t|%ld\t|\n",
               data.ru_stime,
               data.ru_maxrss,
               data.ru_ixrss,
               data.ru_idrss,
               data.ru_isrss,
               data.ru_idrss);

        sleep(1);
    }
    return 0;
}
