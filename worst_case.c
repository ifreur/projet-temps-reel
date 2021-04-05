#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "worst_case.h"

int test_load(Tasksets task,int num){

    if(test_inferior_equal(task,num) == 0){
        
        if(test_equal(task,num) == 1 && isDM(task,num) == 1){
            printf("TODO : implement DM file change");
            exit(-1);
        }

        int border = num * ( pow( (double) 2 , 1/num ) - 1);
        int U = 0;
        for(int i = 0; i < num ; i++)
            U += task[i].C / task[i].D;
        // Etant donné que dans RM, D=T, on peut généralisé la condition suffisante de DM . 

        if(U <= border)
            return 1;
        else 
            if (U <= 1)
                return -1;
            else
                return 0;

    }
    else{
        printf("some D > T\n");            

    } 
    return 1;
}

int test_inferior_equal(Tasksets task,int num){
    for(int i = 0; i < num; i++){
        if(task[i].D > task[i].T){
            return(1);
        }
    }
    return(0);
}

int test_equal(Tasksets task,int num){

    for(int i = 0; i < num; i++){
        if(task[i].D < task[i].T){
            return(1);
        }
    }
    return(0);
}

int isDM(Tasksets task , int num){
    for(int i = 0; i < num -1 ; i++){
        if(task[i].D > task[i+1].D)
            return(1);
    }
    return(0);
}