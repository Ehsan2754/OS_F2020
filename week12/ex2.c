#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    FILE *fp;
    const char *command = "cat /proc/cpuinfo";
    fp = popen(command, "w");
    fprintf(fp, command);
    fclose(fp);
    return 0;
}
