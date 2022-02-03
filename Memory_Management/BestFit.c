#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Block{
    int blockNo;
    int blockSize;
    int occupied;
};

struct File{
    int fileSize;
    int occupiedBlock;
    int occupied;
};

void sortFiles(struct File *root, int n){
    int count = 10;
    while(count != 0){
        count = 0;
        for(int i = 1; i < n; i++){
            if(root[i].fileSize < root[i-1].fileSize){
                struct File temp = root[i];
                root[i] = root[i-1];
                root[i-1] = temp;
                count++;
            }
        }
    }
}

void sortBlocks(struct Block *root, int n){
    int count = 10;
    while(count != 0){
        count = 0;
        for(int i = 1; i < n; i++){
            if(root[i].blockSize < root[i-1].blockSize){
                struct Block temp = root[i];
                root[i] = root[i-1];
                root[i-1] = temp;
                count++;
            }
        }
    }
}
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
        blocks[i].blockNo = i+1;
    }


    struct File files[noOfFiles];
    for(int i = 0; i < noOfFiles; i++){
        printf("Enter size of File %d\n", i+1);
        scanf("%d", &files[i].fileSize);
    }


    for(int i = 0; i < noOfFiles; i++){
        int m = INT_MAX;
        int blockNumber;
        for(int j = 0; j < noOfBlocks; j++){
            if(blocks[j].occupied != 1 && blocks[j].blockSize - files[i].fileSize >= 0){
                if(blocks[j].blockSize - files[i].fileSize < m){
                    m = blocks[j].blockSize - files[i].fileSize;
                    blockNumber = blocks[j].blockNo;
                }
            }
        }
        files[i].occupiedBlock = blockNumber;
        files[i].occupied = 1;
    }

    printf("FILE NO\tFILE SIZE\tOCCUPIED\tBLOCK NO\n");
    for(int i = 0; i < noOfFiles; i++){
        printf("%d\t\t%d\t\t", i+1, files[i].fileSize);
        if(files[i].occupied == 1){
            printf("YES\t\t%d\t\t", files[i].occupiedBlock);
        }else{
            printf("NO\t\t------");
        }
        printf("\n");
    }


}