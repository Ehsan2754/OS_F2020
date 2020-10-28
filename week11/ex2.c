#include <stdio.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
    setvbuf(stdin, NULL, _IOLBF, 5);
    char *text = "Hello";
    int cnt;
    for ( cnt= 0; cnt < 5; ++cnt)
    {
        printf("%c", text[cnt]);
        sleep(1);
    }
    printf("\n");
    return 0;
}
