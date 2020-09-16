#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
void *myThread(void* arg){
  printf("\t -> Hello From Thread #%d!\n",(int)(intptr_t)(arg));
  pthread_exit(NULL);
}
int main(void) {
  printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
  printf("@@@@@@ AHURATHUS Thread CREATOR @@@@@@\n");
  printf("@@@@@ OS-Fall2020 @@@@@@ B19-03 @@@@@@\n");
  printf("@@@@@@@@@@@@@@@@ EHSAN SHAGHAEI @@@@@@\n");
  printf("Enter number of threads to be created!\n");
  printf("N=?(N is an INT)");
  int N;
  scanf("%d",&N);
  int i;
  pthread_t thread;
  for(i=1; i<=N; ++i)
  {
    printf("Creating Thread #%d ...\n",i);
    if(pthread_create(&thread, NULL, myThread,(void*)(intptr_t)i))
    {
      printf("   >>ERROR IN CREATING Thread #%d!\n",i);
      pthread_exit(NULL);
      return 1;
    }
    else
    {
      printf("   >>Thread #%d created!\n",i);
    }
  }
  pthread_exit(NULL);
  return 0;
}
