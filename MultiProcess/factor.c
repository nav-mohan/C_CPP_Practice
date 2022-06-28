/**
 * @file factor.c
 * @author navaneeth mohan
 * @brief Multi-processing to perform prime-factorization
 * @version 0.1
 * @date 2022-06-22
 * @copyright Copyright (c) 2022
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void factor(int n){
    printf("\n----------------------\n");
    printf("\n");
    printf("%d: ",n);
    for (int i = 2; i <= n/2; i++){
        if (n%i == 0){
            printf("%d ", i);
        }
    }
    printf("\n----------------------");
    printf("\n");

}

int main(int argc, char* argv[]){
    int parentPID = getpid();
    int size = 16;
    int* arr;
    arr = (int*)malloc(sizeof(int) * size);

    printf("%d Writing to STDIN\n",getpid());
    for (int i = 0; i < size; ++i)
    {
        arr[i] = (int*)malloc(sizeof(int));
        scanf("%d",&arr[i]);
    }

    pid_t child1, child2, child3;

    if((child1=fork()) == 0){
        printf("I'm child 1\n");
        for (int i = 0; i < size/4; ++i)
        {
            factor(arr[i]);
        }
        _exit(0);
    }
    if((child2=fork()) == 0){
        printf("I'm child 2\n");
        for (int i = size/4; i < size/2; ++i)
        {
            factor(arr[i]);
        }
        _exit(0);
    }
    if((child3=fork()) == 0){
        printf("I'm child 3\n");
        for (int i = size/2; i < 3*size/4; ++i)
        {
            factor(arr[i]);
        }
        _exit(0);
    }
    if(getpid()==parentPID){
        printf("I'm the parent\n");
        for (int i = 3*size/4; i < size; ++i)
        {
            factor(arr[i]);
        }
        exit(0);
    }
}
