#include <stdio.h>

/**************************
 *   Swaps two integers 
 ************************/

void _swap(int *a, int *b)
{
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

void bubble_sort(int *array, int size)
{
    for (int i = size - 1; i >= 0; i--)
        for (int j = 0; j < i; j++)
            if (array[j] > array[j + 1])
                _swap(&array[j], &array[j + 1]);
}
int main(int argc, char const *argv[])
{
    int array[101], n;
    printf("ENTER NUMBER OF ENTRIES(N<100, N MUST BE AN INTEGER)\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("ENTER ENTRY #%d (ENTRY MUST BE AN INTEGER)\n", i + 1);
        scanf("%d", &array[i]);
    }
    bubble_sort(array, n);
    printf("====YOUR SORTED ARRAY IS :====\n");
    for (int i = 0; i < 4; i++)
        printf("[# %d] => %d\n", i + 1, array[i]);
    return 0;
}
