#include <stdio.h>
int main(int argc, char const *argv[])
{
    int input;
    int errFlag = sscanf(argv[1], "%d",&input);
    if (!errFlag)
    {
        printf("Malform input!");
        return 0;
    }
    int i;
    for (i = 0; i < input; i++)
    {
        int j;
        int space = input-i;
        for (int j = 0; j < space; j++) putchar(' ');
        for (int j = 0; j < 2*i+1 ; j++) putchar('*');
        putchar('\n');
    }
    
    return 0;
}
