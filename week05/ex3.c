#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include  <time.h>
/********************************
* Following macros can be changed
* in your convinience.
*********************************/
#define EMPTY  0
#define INIT_VALUE 0x64
#define BUFFER_SIZE 0x05
/******************************
* End of macro definition
*******************************/
int buff[BUFFER_SIZE] = {[0]= INIT_VALUE};
int elemIndex=0;
int producerLock=1;
int consumerLock=0;
void * producer(void *arg){
    while(1){
        for(;!producerLock;);
        if (elemIndex == BUFFER_SIZE){
            producerLock=0;
            consumerLock=1;
            printf("**BUFFER IS FULL!\n");
            continue;
            }
        buff[elemIndex] = elemIndex + INIT_VALUE;
        printf(">> PRODUCER: New data produced in the buffer[INDEX #%d: 0x%x]\n",elemIndex,buff[elemIndex]);
        elemIndex++;
    }
    pthread_exit(NULL);
    return 0;
    }
void * consumer(void *arg){
    while(1){
        for(;!consumerLock;);
        if (elemIndex==0){
            producerLock=1;
            consumerLock=0;
            printf("**NO DATA TO CONSUME!\n");
            continue;
            }
        int data =buff[--elemIndex];
        buff[elemIndex]=EMPTY;
        printf(">> CONSUMER: Produced data consumed from the buffer[INDEX #%d: EMPTY]\n",elemIndex);
        
    }
    pthread_exit(NULL);
    return 0;

}
int main(){
    printf("****************************************\n");
    printf("****AHURATUS Producer/Consumer in C*****\n");
    printf("****OS-Fall 2020*****Ehsan Shaghaei*****\n");
    printf("****************************************\n");
    printf("***** >>>PRESS CTRL-Z to EXIT **********\n");
    printf(">>>PROGRAM STARTS IN 5-SECONDS...\n");
    printf("\t*** >>>PRESS CTRL-Z to EXIT \n");
    sleep(3);
    printf(">>>PROGRAM STARTS IN 2-SECONDS...\n");
    printf("\t*** >>>PRESS CTRL-Z to EXIT \n");
    sleep(1);
    printf(">>>PROGRAM STARTS IN 1-SECOND...\n");
    printf("\t*** >>>PRESS CTRL-Z to EXIT \n");
    sleep(1);
    printf("\t*** STARTING .... \n");
    pthread_t consumer_t;
    pthread_t producer_t;
    pthread_create(&producer_t,NULL,producer,NULL);
    pthread_create(&consumer_t,NULL,consumer,NULL);
    pthread_join(consumer_t,NULL);
    pthread_join(producer_t,NULL);
    pthread_exit(NULL);
    return 0;
}
