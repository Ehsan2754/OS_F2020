#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main()
{
	printf("*********************************************\n");
	printf("*AHURATUS SHELL*****************VERSION*1.0**\n");
	printf("*BS19-03****OS[F2020]****EHSAN SHAGHAEI******\n");
	printf("*********************************************\n");
	printf("*NOTE : IN EX3 ALL ARGS ARE IGNORED**********\n");
	printf(">COMMAND LENGTH<100CHAR >Press Ctrl+C to quit\n");	
	char command [1000];
	const char EXIT[5] = "EXIT"; 
	char* p ;	
	while(-1)
	{
 	
	
	fgets(command,1000,stdin);
	char *arg [100];
	int i = 0;
	for(i = 0; i<100; ++i)
	{
		arg[i] = NULL;
	}
	arg [0] = (char*)malloc(100);
	
	int j=0,k=0;
	i = 0;
	
	while(-1){
		if(command[i]!=' ' && command[i]!='\n' && command[i] != '\0')
		{	arg[j][k++] = command[i++];
		}
		else if (command[i] == ' ')
		{
			k=0;
			i++;
			j++;
			arg[j] = (char*)malloc(100);
	
		}	
		else
		{
			break;
		}
	}

	pid_t pid = fork();
	if(pid == 0)
	{	  
		execvp(arg[0],arg);
		
	}
		

	}

	return 0;
}
