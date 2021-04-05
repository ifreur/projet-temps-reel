#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "worst_case.h"

int test_load(Tasksets task,int num){

    if(test_inferior_equal(task.process,num) == 0){
        
        if(test_equal(task.process,num) == 1 && isDM(task.process,num) == 1){
            printf("TODO : implement DM file change");
            exit(-1);
        }

        int border = num * ( pow( (double) 2 , 1/num ) - 1);
        int U = 0;
        for(int i = 0; i < num ; i++)
            U += task.process[i].C / task.process[i].D;
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

int test_inferior_equal(Process* task,int num){
    for(int i = 0; i < num; i++){
        if(task[i].D > task[i].T){
            return(1);
        }
    }
    return(0);
}

int test_equal(Process* task,int num){

    for(int i = 0; i < num; i++){
        if(task[i].D < task[i].T){
            return(1);
        }
    }
    return(0);
}

int isDM(Process* task , int num){
    for(int i = 0; i < num -1 ; i++){
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
            bpi += ( (int) ceil((double) x / (double) task.process[k].T) ) * task.process[k].C ;
        }
    }
    return bpi;
}



int get_nb_critical_job(Tasksets task, int i , int bp){
    return(( (int) ceil((double) bp/ (double) task.process[i-1].T) ));
}

int get_response_time(Tasksets task, int i, int k){
    int t_max = (k+1) * task.process[i-1].T; 
    int t = k * task.process[i-1].T; 
    int c = task.process[i-1].C;
    int * tab = fp_compute(task.process,task.len,t_max);
    printf("time: %d %d Tablo :\n",t_max,t);

    for(int j = 0; j < task.process[i-1].T; j++){
        printf("[ %d %d ]",tab[t+j],t+j);

        if(tab[t+j] == i )
            c--;

        if(c == 0)
            return j+1;
    }
    return -1;
}

int get_worst_case_response_time(Tasksets task, int i){

}

