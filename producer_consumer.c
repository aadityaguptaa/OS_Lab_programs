#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<omp.h>


int mutex = 1;
int empty = 10;
int full = 0;
int x = 0;

void producer(){
    mutex--;
    empty--;
    full++;
    x++;
    printf("Producer produced %d\n", x);
    mutex++;
}


void consumer(){
    mutex--;
    empty++;
    full--;
    printf("Consumer consumed %d\n", x);
    x--;
    mutex++;
}
int main(void){
    printf("Enter your choice\n1.Producer\n2.Consumer\n3.Exit\n");
    int n;
#pragma omp critical
    for(int i = 0; i >= 0; i++){
        scanf("%d", &n);
        switch(n){
            case 1:
                if(empty != 0 && mutex == 1){
                    producer();
                }else{
                    printf("Buffer is full\n");
                }
                break;
            case 2:
                if(full != 0 && mutex == 1 ){
                    consumer();
                }else{
                    printf("Buffer is empty\n");
                }
                break;
            case 3:
                return 0;
        }
    }
}