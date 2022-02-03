#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int search(int arr[], int num, int n){
    for(int i = 0; i < n; i++){
        if(arr[i] == num){
            return 1;
        }
    }
    return 0;
}

void display(int arr[], int n){
    for(int i = 0; i <= n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void){
    int n;
    printf("Enter length of ref string\n");
    scanf("%d", &n);
    int inputs[n];
    printf("Enter numbers\n");
    for(int i = 0; i < n;i++){
        scanf("%d", &inputs[i]);
    }

    printf("Enter frame length\n");
    int frameLength;
    scanf("%d", &frameLength);

    int arr[frameLength];
    int counter[frameLength];

    for(int i = 0; i < frameLength; i++){
        arr[i] = -1;
        counter[i] = 1;
    }

    for(int i = 0; i < n; i++){
        int flag = 0;
        for(int j = 0; j < frameLength; j++){
            if(arr[j] == inputs[i]){
                flag = 1;
                counter[j] = 0;
            } else{
                counter[j]++;
            }
        }

        if(flag == 0){
            int m = INT_MIN;
            int index;
            for(int j = 0; j < frameLength; j++){
                if(counter[j] > m){
                    m = counter[j];
                    index = j;
                }
            }
            arr[index] = inputs[i];
            counter[index] = 0;
        }
        display(arr, frameLength-1);
    }
}
