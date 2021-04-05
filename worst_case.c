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

int get_busy_period(Tasksets task, int i,int t){
    // Probleme pour le moment, comprends pas l'énoncé 
    int bpi = 0;

    for(int k = 0 ; k < i ; k++){
        bpi += ( (int) ceil((double) t/ (double) task[k].T) ) * task[k].C ;
    }
    if(bpi > t)
        return t;
    return bpi;
}



int get_nb_critical_job(Tasksets task, int i , int bp){
    return(( (int) ceil((double) bp/ (double) task[i-1].T) ));
}

int get_response_time(Tasksets task,int tlen, int i, int k){
    int t_max = (k+1) * task[i-1].T; 
    int t = k * task[i-1].T; 
    int c = task[i-1].C;

    int * tab = fp_compute(task,tlen,t_max);
    printf("time: %d %d Tablo :\n",t_max,t);

    for(int j = 0; j < task[i-1].T; j++){
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

