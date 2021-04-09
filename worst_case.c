#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "worst_case.h"

int test_load(Tasksets task,int task_lenght){

    if(test_inferior_equal(task,task_lenght) == 0){
        
        if(test_equal(task,task_lenght) == 1 && isDM(task,task_lenght) == 1){
            printf("TODO : implement DM file change");
            exit(-1);
        }

        int border = task_lenght * ( pow( (double) 2 , 1/task_lenght ) - 1);
        int U = 0;
        for(int i = 0; i < task_lenght ; i++)
            U += task[i].C / task[i].D;
        // Etant donné que dans RM, D=T, on peut généralisé la condition suffisante de DM . 

        if(U <= border)
            return 1;
        else 
            if (U <= 1)
                return 0;
            else
                return -1;

    }
    else{
        printf("some D > T \n");            
        printf("TODO : implement file change");
    } 
    return -2; 
}

int test_inferior_equal(Tasksets task,int task_lenght){
    for(int i = 0; i < task_lenght; i++){
        if(task[i].D > task[i].T){
            return(1);
        }
    }
    return(0);
}

int test_equal(Tasksets task,int task_lenght){

    for(int i = 0; i < task_lenght; i++){
        if(task[i].D != task[i].T){
            return(1);
        }
    }
    return(0);
}

int isDM(Tasksets task , int task_lenght){
    for(int i = 0; i < task_lenght -1 ; i++){
        if(task[i].D > task[i+1].D)
            return(1);
    }
    return(0);
}

int get_busy_period(Tasksets task, int i){
    int bpi = 1;
    int x;

    while(x != bpi){

        x = bpi;
        bpi = 0;

        for(int k = 0 ; k < i ; k++){
            bpi += ( (int) ceil((double) x / (double) task[k].T) ) * task[k].C ;
        }
    }
    return bpi;
}

int get_nb_critical_job(Tasksets task, int i , int bp){
    return(( (int) ceil((double) bp/ (double) task[i-1].T) ));
}

int get_response_time(Tasksets task, int i, int k){
    int activation = (k-1) * task[i-1].T;

    int Fi = 1;
    int t = 0;

    while(t != Fi){

        t = Fi;
        Fi = 0;
        for(int x = 0 ; x < (i-1) ; x++){
            Fi += (( (int) ceil((double) t / (double) task[x].T) ) * task[x].C )  ;
        }
        Fi +=  (k * task[i-1].C);
    }
    return Fi -activation ;
}

int get_worst_case_response_time(Tasksets task, int i){
    int busy_period = get_busy_period(task,i);
    int nb_job = get_nb_critical_job(task,i,busy_period);

    int worst_time = 0;
    int tmp;
    for(int j = 1; j <= nb_job ; j++){
        tmp = get_response_time(task,i,j);
        if(tmp > worst_time)
            worst_time = tmp;
    }
    return worst_time;
}

int get_response_time_preemptive(Tasksets task, int len, int i, int k){
    int activation = (k-1) * task[i-1].T;

    int Fi = 1;
    int t = 0;

    int B = task[i].C;
    for(int j = 1 ; j < len; j++)
        if(task[i].C > B)
            B = task[i].C;

    while(t != Fi){

        t = Fi;
        Fi = 0;
        for(int x = 0 ; x < (i-1) ; x++){
            Fi += (( ( (int) ceil((double) t + 1 )/ (double) task[x].T) ) * task[x].C )  ;
        }
        Fi +=  (k * task[i-1].C) + B;
    }
    return Fi -activation ;
}

int get_worst_case_response_time_preemptive(Tasksets task,int len, int i){
    int busy_period = get_busy_period(task,i);
    int nb_job = get_nb_critical_job(task,i,busy_period);

    int worst_time = 0;
    int tmp;
    for(int j = 1; j <= nb_job ; j++){
        tmp = get_response_time_preemptive(task,len,i,j) + task[i].C - (j*task[i].T);
        if(tmp > worst_time)
            worst_time = tmp;
    }
    return worst_time;
}