#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct File{
    char fileName[50];
    int startingBlock;
    int noOfBlocks;
};

int main(void){

    int n;
    printf("Enter no of files\n");
    scanf("%d", &n);
    struct File fileList[n];

    for(int i = 0; i < n; i++){
        printf("Enter File Name %d\n", i+1);
        scanf("%s", fileList[i].fileName);
        printf("Enter starting block of file %d\n", i+1);
        scanf("%d", &fileList[i].startingBlock);
        printf("Enter number of blocks occupied\n");
        scanf("%d", &fileList[i].noOfBlocks);

    }

    printf("Enter the file to be searched\n");
    char searchFile[50];
    scanf("%s", searchFile);

    for(int i = 0; i < n; i++){
        if(strcmp(searchFile, fileList[i].fileName) == 0){
            printf("FILE NAME\tSTART BLOCK\tNO OF BLOCKS\tBLOCKS OCCUPIED\n");
            printf("%s\t\t%d\t\t%d\t\t", fileList[i].fileName, fileList[i].startingBlock, fileList[i].noOfBlocks );
            for(int j = 0; j < fileList[i].noOfBlocks; j++){
                printf("%d, ", fileList[i].startingBlock + j);
            }
            printf("\n");
        }
    }
}