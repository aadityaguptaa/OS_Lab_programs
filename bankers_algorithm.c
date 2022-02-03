#include<stdio.h>
#include<stdlib.h>


int main(void){
    int n;
    printf("Enter Number of processes\n");
    scanf("%d", &n);

    int noOfResources;
    printf("Enter number of resources\n");
    scanf("%d", &noOfResources);

    int allocated[n][noOfResources];
    int max[n][noOfResources];
    int availableResources[noOfResources];
    int need[n][noOfResources];
    int f[n];

    for(int i = 0; i < n; i++){
        f[i] = 0;
    }

    for(int i = 0; i < n; i++){
        printf("Enter details of Process %d\n", i+1);
        printf("Enter Allocated Memory\n");
        for(int j = 0; j < noOfResources; j++){
            scanf("%d", &allocated[i][j]);
        }
        printf("Enter Max requires Memory\n");
        for(int j = 0; j < noOfResources; j++){
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter Available resource\n");
    for(int i = 0; i < noOfResources; i++){
        scanf("%d", &availableResources[i]);
    }

    int ans[n];

    for(int  i = 0; i < n; i++){
        for(int j = 0; j < noOfResources; j++){
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }
    int y = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(f[i] == 0){
                int flag = 0;

                for(int k = 0; k < noOfResources; k++){
                    if(need[j][k] > availableResources[k]){
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0){
                    ans[y] = j;
                    y++;
                    for(int k = 0; k < noOfResources; k++){
                        availableResources[k] += allocated[j][k];
                    }
                    f[j] = 1;
                }
            }
        }
    }

    int flag = 1;

    for(int i=0;i<n;i++)
    {
        if(f[i]==0)
        {
            flag=0;
            printf("The following system is not safe");
            break;
        }
    }

    if(flag==1)
    {
        printf("Following is the SAFE Sequence\n");
        for (int i = 0; i < n - 1; i++)
            printf(" P%d ->", ans[i]);
        printf(" P%d", ans[n - 1]);
    }


    return (0);


}