/**********************************************
 * Running top meanwhile './ex2' is running on
 * background, shows that the process 'ex2' in 
 * process list shows how %MEM for this parti-
 * cular process is increasing.
 * *********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#define SIZE 10
#define MEGABYTE 1000000
#define INIT_VAL 0
int main(int argc, char const *argv[])
{
    printf("#########################################################\n");
    printf("####AHURATUS MEM ALLOCATOR#########WEEK08################\n");
    printf("####EHSAN SHAGHAEI#################OS-FALL2020###########\n");
    printf("#########################################################\n");
    for (int i = 0; i < 10; i++)
    {
        memset(calloc(SIZE * MEGABYTE, 1), INIT_VAL, SIZE * MEGABYTE);
        printf(">> MEM ALLOCATOR: 10MB were allocated!\n");
        sleep(10);
    }
    return 0;
}
