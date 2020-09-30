#include <stdio.h>
#include <stdlib.h>
int main()
{
printf("********************************************\n");
printf("Dynamic*MEM-Allocator********B19-03*OS-F2020\n");
printf("********************************************\n");
printf(" > ENTER N's VALUE? (N is UNSIGNED INTEGER)\n");
int n;
scanf("%d",&n);
int* m = malloc(n*sizeof(int));
printf("Dynamic Array allocated with address %p\n",m);
for(int i=0;i<n;++i)
{
	*(m+i) = i;
	printf("#INDEX #%d in ADD%p -> VAL = %d\n",i,(m+i),*(m+i));
}
free(m);
return 0;
}
