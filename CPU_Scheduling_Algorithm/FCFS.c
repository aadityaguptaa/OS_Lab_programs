#include<stdio.h>
#include<stdlib.h>

struct Process{
    int burstTime;
};

int main(void){
    int n;
    printf("Enter Number of Processes\n");
    scanf("%d", &n);
    struct Process processList[n];

    for(int i = 0; i < n; i++){
        struct Process *tempProcess = (struct Process *) malloc(sizeof (struct Process));
        printf("Enter Burst Time for Process %d\n", i+1);

        int burstTime;
        scanf("%d", &burstTime);
        tempProcess -> burstTime = burstTime;

        processList[i] = *tempProcess;
    }
    int waitingTime = 0;
    int turnAroundTime = 0;

    printf("Process ID\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(int i = 0; i < n; i++){
        turnAroundTime = waitingTime + processList[i].burstTime;
        printf("%d\t%d\t%d\t%d\t\n", i+1, processList[i].burstTime, waitingTime, turnAroundTime);
        waitingTime += processList[i].burstTime;
    }
}