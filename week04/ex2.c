#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
	int i,n ;
	//n = 3;
	n = 5;
	for( i = 0; i<5; ++i)
	{
		fork();
	}
	sleep(5);
	return EXIT_SUCCESS;
}
