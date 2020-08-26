#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(int argc, char const *argv[])
{
    /* code */
    int _int = INT_MAX;
    float _float = FLT_MAX;
    double _double = DBL_MAX;
    printf("|---TYPE---|----SIZE----|------------------MAX  VALUE------------------|\n");
    printf("|*  INT    | %.10li |%.46i|\n",sizeof(_int),_int);
    printf("|*  FLOAT  | %.10li |%f|\n",sizeof(_float),_float);
    printf("|*  DOUBLE | %.10li |%lf|\n",sizeof(_double),_double);

    return 0;
}
