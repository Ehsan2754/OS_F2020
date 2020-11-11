#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *file;
    file = fopen("input.txt", "r");
    int *A, *C, *E, *R;
    int pc = 0, rc = 0;
    E = calloc(10, sizeof(int) * rc);
    A = calloc(10, sizeof(int) * rc);
    C = (int *)malloc(rc * pc * sizeof(int));
    R = (int *)malloc(rc * pc * sizeof(int));
    int *status = calloc(0, sizeof(int) * pc);
    fscanf(file, "%d %d", &rc, &pc);
    for (int i = 0; i < rc; i++)
        fscanf(file, "%d", &E[i]);
    for (int i = 0; i < rc; i++)
        fscanf(file, "%d", &A[i]);
    for (int i = 0; i < pc; i++)
        for (int j = 0; j < rc; j++)
            fscanf(file, "%d", (C + i * rc + j));

    for (int i = 0; i < pc; i++)
        for (int j = 0; j < rc; j++)
            fscanf(file, "%d", (R + i * rc + j));

    for (;;)
    {
        int CNT = 0;
        for (int i = 0; i < pc; i++)
            if (status[i] == 0)
                CNT = CNT + 1;
        for (int i = 0; i < pc; i++)
        {
            if (status[i] == 0)
            {
                for (int j = 0; j < rc; j++)
                {
                    if (*(R + i * rc + j) - *(C + i * rc + j) - A[j] <= 0)
                        status[i] = 1;
                    else
                    {
                        status[i] = 0;
                        break;
                    }
                }
                if (status[i] == 1)
                {
                    for (int j = 0; j < rc; j++)
                        A[j] = *(C + i * rc + j) + A[j];
                    printf("Process %d finished \n", i);
                    break;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < pc; i++)
        {
            if (status[i] == 0)
                count = count + 1;
        }
        if (count == 0)
        {
            printf("All processes are terminated");
            break;
        }
        if (CNT - count == 0)
        {
            printf("Deadlocks");
            break;
        }
    }
    return 0;
}