#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
    char input[100];
    int i = 0;
    scanf("%s",input);
    for ( i = strlen(input); i >= 0; i--)
    {
        putchar(input[i]);
    }
    return 0;
}
