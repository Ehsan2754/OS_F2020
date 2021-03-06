#include <stdio.h>
typedef struct Process{
int processIndex;
int BT;
int AT;
int TAT;
int CT;
int WT;
} Process;
void FIFO_Scheduler(struct Process * p,int n);
void SJN_Scheduler(struct Process * p,int n);
int main(){
  printf("********************************************************\n");
	printf("************AHURATUS SHELL*****************WEEK 06******\n");
	printf("************BS19-03****OS[F2020]****EHSAN SHAGHAEI******\n");
	printf("********************************************************\n");
    int N;
    printf("Enter number of processes:(Entry is UNSIGNED INTEGER)\n");
    scanf("%d",&N);
    Process P[N];
    for(int i=0;i<N;i++){
        P[i].processIndex=i;
        printf("Enter process #%d arrival time:(UNSIGNED INTEGER)\n",i);
        scanf("%d",&P[i].AT);
        printf("Enter process #%d burst time:(UNSIGNED INTEGER)\n",i);
        scanf("%d",&P[i].BT);
    }
    SJN_Scheduler(P,N);
    int cmplting_time=0;
    for(int i=0;i<N;i++){
        if (P[i].AT-cmplting_time>=0)
            cmplting_time =cmplting_time+ P[i].BT+(P[i].AT-cmplting_time);
        else
            cmplting_time =cmplting_time+ P[i].BT;
        P[i].CT=cmplting_time;
    }
    int TurnAroundTime=0;
    int WaitingTime=0;
    for(int i=0;i<N;i++){
        P[i].TAT=P[i].CT-P[i].AT;
        TurnAroundTime+=P[i].TAT;
        P[i].WT=P[i].TAT-P[i].BT;
        WaitingTime+=P[i].WT;
    }
    printf("|Pr \t| AT \t| BT \t| CT \t| TAT \t| WT \t|\n");
    for(int i=0;i<N;i++)
        printf("|%d \t| %d \t| %d \t| %d \t| %d \t| %d \t|\n",P[i].processIndex,P[i].AT,P[i].BT,P[i].CT,P[i].TAT,P[i].WT);
    
    printf("Average Turn-around time is: %d\n",TurnAroundTime/N);
    printf("Average Waiting time is: %d\n",WaitingTime/N);
}
void FIFO_Scheduler(struct Process * p,int n){
    for (int i=1;i<n;i++){
        for(int j=0;j<n-1;j++){
            if (p[i].AT<p[j].AT){
                Process t=p[i];
                p[i]=p[j];
                p[j]=t;
            }
        }
    }
}
void SJN_Scheduler(struct Process * p,int n){
    for (int i=1;i<n;i++){
        for(int j=0;j<n-1;j++){
            if (p[i].BT<p[j].BT ){
                Process t=p[i];
                p[i]=p[j];
                p[j]=t;
            }
        }
    }
    for(int i=0;i<n;i++){
        if (p[i].AT<p[0].AT){
            Process t=p[0];
            p[0]=p[i];
            p[i]=t;
        }
    }

    for(int j=1;j<n-1;j++){
        int t1=p[j-1].AT;
        int t2=p[j-1].BT+t1;
        for(int i=j+1;i<n;i++){
            if (p[i].AT<p[j].AT && t2>p[i].AT &&p[i].BT<p[j].BT){
                Process t=p[j];
                p[j]=p[i];
                p[i]=t;
            }
        }
    }

}