#include<stdio.h>
#include<stdlib.h>

struct Process{
    int burstTime;
    int priority;
    int waitingTime;
};

void sort(struct Process *root, int n){

    int count = 10;
    while(count != 0){
        count = 0;
        for(int i = 1; i < n; i++){
            if(root[i].priority < root[i-1].priority){
                struct Process temp = root[i];
                root[i] = root[i-1];
                root[i-1] = temp;
                count++;
            }
        }
    }
}

int main(void){
    int n;
    printf("Enter the number of processes\n");
    scanf("%d", &n);

    struct Process processList[n];

    for(int i = 0; i < n; i++){
        printf("Enter Process %d burst time\n", i+1);
        int burstTime;
        scanf("%d", &burstTime);
        printf("System/User Process? (0/1)\n");
        int priority;
        scanf("%d", &priority);
        struct Process *temp = (struct Process *) malloc(sizeof (struct Process));
        temp ->burstTime = burstTime;
        temp -> priority = priority;
        processList[i] = *temp;
    }

    sort(processList, n);

    int waitingTime = 0;
    printf("Process ID\tPriority\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(int i = 0; i < n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, processList[i].priority, processList[i].burstTime, waitingTime, waitingTime + processList[i].burstTime);
        waitingTime += processList[i].burstTime;
    }



}