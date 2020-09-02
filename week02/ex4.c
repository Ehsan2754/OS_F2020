#include <stdio.h>
void _swap(int *a, int *b);
int main(int argc, char const *argv[])
{
    int a, b;
    printf("Enter a and b!\n");
    int errFlag = scanf("%d %d", &a, &b);
    if (!errFlag)
    {
        printf("Malform input!");
        return 0;
    }
    printf("VAR a; ADDR = %p => VAL = %d\n", &a, a);
    printf("VAR b; ADDR = %p => VAL = %d\n", &b, b);
    _swap(&a, &b);
    printf("SWAPPING...\n");
    printf("VAR a; ADDR = %p => VAL = %d\n", &a, a);
    printf("VAR b; ADDR = %p => VAL = %d\n", &b, b);
    return 0;
}
void _swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}