#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	printf("*********************************************\n");
	printf("*AHURATUS SHELL*****************VERSION*1.0**\n");
	printf("*BS19-03****OS[F2020]****EHSAN SHAGHAEI******\n");
	printf("*********************************************\n");
	printf("*NOTE : IN EX3 ALL ARGS ARE IGNORED**********\n");
	printf(">COMMAND LENGTH<100CHAR   >Type'EXIT' to quit\n");	
	char command [100];
	const char EXIT[5] = "EXIT"; 
	while(strcmp(command,EXIT))
	{
	printf("\nAHURATUS SHELL $ ");
	scanf("%s",command);
	system(command);	
	}

	return 0;
}
