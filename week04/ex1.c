#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	pid_t p;
	p = fork();
	const int n = 23; 
	if(p>0)
	{
		// PID>0  ==> parent case
		printf("* Hello from parent [%d - %d]\n",p,n);
	}
	else if (p == 0)
	{
		// PID==0 ==> child case
		printf("* Hello from child [%d - %d]\n",p,n);
	}
	else 
	{     
		// PID<0  ==> error case
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;

}
