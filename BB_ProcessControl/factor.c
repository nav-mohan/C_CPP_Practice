/**
 * @file factor.c
 * @author navaneeth mohan
 * @brief Multi-threading to perform a computationally intensive task | Objective - Find Prime Numbers
 * @version 0.1
 * @date 2022-06-22
 * @copyright Copyright (c) 2022
*/
// This is the admin file. it collects input from STDIN, forks to child processes, and prints to STDOUT


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void factor(int n){
    for (int i = 2; i <= n/2; i++){
        if (n%i == 0){
            printf("%d ", i);
        }
    }
}

int main(int argc, char* argv[]){
    int size = 16;
    // scanf("%d", &size);
    printf("%d\n",argc);
    int* arr;
    arr = (int *)malloc(sizeof(int) * size);

    for(int j = 0; j < size; j++){
        scanf("%d", &arr[j]);
    }

    int childnum = 0;
    pid_t pid0 = fork();
    childnum++;
    pid_t pid1 = fork();
    childnum++;
    pid_t pid2 = fork();
    childnum++;
    pid_t pid3 = fork();

    // the parent
    if(pid0 && pid1 && pid2 && pid3){
        printf("I'm the parent\n");
        // wait until all child pid==0 i.e all of the child fork()s finish executing
        int status;
        pid_t child; // this is the PID of the child that died. wait() returns this value
        child = wait(&status);
        child = wait(&status);// we have to call wait() 4 times
        child = wait(&status);// because we have 4 child processes
        child = wait(&status);
    }
        // Im child 0
    if(pid0==0 && childnum==0){
        printf("I'm child%d\n",childnum);
        int lines = size/4;
        int start = 4 * childnum;
        for (int i = 0; i < start+4; ++i)
        {
            printf("%d: ", arr[i]);
            factor(arr[i]);
            printf("------------\n");
        }
        exit(0);
    }

    // child 1
    if(pid1==0 && childnum==1){
        printf("I'm child%d\n",childnum);

        int lines = size/4;
        int start = 4 * childnum;
        for (int i = 0; i < start+4; ++i)
        {
            printf("%d: ", arr[i]);
            factor(arr[i]);
            printf("------------\n");
        }
        exit(0);
    }

    // child 2
    if(pid2==0 && childnum==2){
        printf("I'm child%d\n",childnum);
        int lines = size/4;
        int start = 4 * childnum;
        for (int i = 0; i < start+4; ++i)
        {
            printf("%d: ", arr[i]);
            factor(arr[i]);
            printf("------------\n");
        }
        exit(0);
    }

    // child 3
    if(pid3==0 && childnum==3){
        printf("I'm child%d\n",childnum);

        int lines = size/4;
        int start = 4 * childnum;
        for (int i = 0; i < start+4; ++i)
        {
            printf("%d: ", arr[i]);
            factor(arr[i]);
            printf("------------\n");
        }
        exit(0);
    }

}