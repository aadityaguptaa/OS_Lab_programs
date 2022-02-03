#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Process{
    int memoryRequired;
    int occupied;

};

int main(void){
    int memoryAvailable;
    printf("Enter available memory\n");
    scanf("%d", &memoryAvailable);


    int n;
    printf("Enter the number of processes\n");
    scanf("%d", &n);

    struct Process processList[n];
    for(int i = 0; i < n; i++){
        printf("Enter memory required for file %d\n", i+1);
        scanf("%d", &processList[i].memoryRequired);
    }

    int memoryLeft = memoryAvailable;
    for(int i = 0; i < n; i++){
        if(memoryLeft - processList[i].memoryRequired >= 0){
                processList[i].occupied = 1;
                memoryLeft -= processList[i].memoryRequired;
        }
    }

    printf("PROCESS ID\tMEMORY REQUIRED\tOCCUPIED\n");
    for(int i = 0; i < n; i++){
        printf("%d\t\t%d\t\t", i + 1, processList[i].memoryRequired );
        if(processList[i].occupied == 1){
            printf("YES\t\t");
        }else{
            printf("NO\t\t");
        }
        printf("\n");
    }

}