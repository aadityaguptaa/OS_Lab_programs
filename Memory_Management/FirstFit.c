#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Block{
    int blockSize;
    int occupied;
};

struct File{
    int fileSize;
    int occupiedBlock;
    int occupied;
};
int main(void){
    int noOfBlocks;
    printf("Enter Number of Blocks\n");
    scanf("%d", &noOfBlocks);

    int noOfFiles;
    printf("Enter no of files\n");
    scanf("%d", &noOfFiles);

    struct Block blocks[noOfBlocks];
    for(int i = 0; i < noOfBlocks; i++){
        printf("Enter size of block %d\n", i+1);
        scanf("%d", &blocks[i].blockSize);
    }


    struct File files[noOfFiles];
    for(int i = 0; i < noOfFiles; i++){
        printf("Enter size of File %d\n", i+1);
        scanf("%d", &files[i].fileSize);
    }

    for(int i = 0; i < noOfFiles; i++){
        for(int j = 0; j < noOfBlocks; j++){
            if(blocks[j].blockSize >= files[i].fileSize && blocks[j].occupied != 1){
                files[i].occupiedBlock = j;
                blocks[j].occupied = 1;
                files[i].occupied = 1;
                break;
            }
        }
    }

    printf("FILE NO\tFILE SIZE\tOCCUPIED\tBLOCK NO\n");
    for(int i = 0; i < noOfFiles; i++){
        printf("%d\t\t%d\t\t", i+i, files[i].fileSize);
        if(files[i].occupied == 1){
            printf("YES\t\t%d\t\t", files[i].occupiedBlock);
        }else{
            printf("NO\t\t------");
        }
        printf("\n");
    }


}