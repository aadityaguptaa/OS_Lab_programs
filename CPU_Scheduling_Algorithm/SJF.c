#include<stdio.h>
#include<stdlib.h>

struct Process{
    int burstTime;
};

void sortProcesses(struct Process *root, int n){

    int count = 10;
    while(count != 0){
        count = 0;
        for(int i = 1; i < n; i++){
            if(root[i].burstTime < root[i-1].burstTime){
                count++;
                struct Process temp = root[i-1];
                root[i-1] = root[i];
                root[i] = temp;
            }
        }

    }
}

int main(void){
    int n;
    printf("Enter number of Processes\n");
    scanf("%d", &n);
    struct Process processList[n];

    for(int i = 0; i < n; i++){
        printf("Enter Burst Time of Process %d\n", i+1);
        int burstTime;
        scanf("%d", &burstTime);

        struct Process *temp = (struct Process *) malloc(sizeof (struct Process));
        temp -> burstTime = burstTime;
        processList[i] = *temp;
    }

    sortProcesses(processList, n);
    int waitingTime = 0;
    int turnAroundTime = 0;

    printf("Process ID\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(int i = 0; i < n; i++){
        turnAroundTime = waitingTime + processList[i].burstTime;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\n", i+1, processList[i].burstTime, waitingTime, turnAroundTime);
        waitingTime += processList[i].burstTime;
    }
}