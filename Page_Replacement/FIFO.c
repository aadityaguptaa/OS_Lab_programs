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

    int arr[100];
    for(int i = 0; i < 100; i++){
        arr[i] = -1;
    }
    int oldestElement = 0;

    for(int i = 0; i < n; i++){
        if(search(arr, inputs[i], frameLength) == 1){
            display(arr, frameLength-1);
        }else{
            arr[oldestElement] = inputs[i];
            oldestElement++;
            if(oldestElement >= frameLength){
                oldestElement = 0;
            }
            display(arr, frameLength-1);
        }
    }
}
