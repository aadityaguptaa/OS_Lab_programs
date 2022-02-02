#include<stdio.h>
#include<stdlib.h>

struct Process{
    int burstTime;
    int burstTimeTemp;
    int waitingTime;
    int turnAroundTime;
};

int main(void){
    int n;
    printf("Enter the number of processes\n");
    scanf("%d", &n);

    struct Process processList[n];

    for(int i = 0; i < n; i++){
        printf("Enter burst time of process %d\n", i+1);
        int burstTime;
        struct Process *temp = (struct Process *) malloc(sizeof (struct Process));
        scanf("%d", &burstTime);
        temp -> burstTimeTemp = burstTime;
        temp -> burstTime = burstTime;
        temp -> waitingTime = 0;
        processList[i] = *temp;
    }

    int timeSlice;
    printf("Enter time of time slice\n");
    scanf("%d", &timeSlice);

    int count = 10;
    int waitingTime = 0;
    while (count != 0){
        count = 0;
        for(int i = 0; i < n; i++){
            if(processList[i].burstTimeTemp <= 0){
                continue;
            } else{
                count++;
                if(processList[i].burstTimeTemp <= timeSlice){
                    waitingTime += processList[i].burstTimeTemp;
                    processList[i].waitingTime = waitingTime - processList[i].burstTime;
                } else{
                    waitingTime += timeSlice;

                }
                processList[i].burstTimeTemp -= timeSlice;

            }
        }
    }

    printf("Process ID\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(int i = 0; i < n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\n", i+1, processList[i].burstTime, processList[i].waitingTime, processList[i].burstTime + processList[i].waitingTime);
    }

}