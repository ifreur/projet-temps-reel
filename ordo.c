#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordo.h"
#include "lib_sorted_job_list/sorted_job_list.h"

void read_file(char* filePath, Process** myProcess,int * lenProcess){
    FILE * file = fopen(filePath,"r");
    fscanf(file,"%d",lenProcess);
    *myProcess = malloc((*lenProcess) * sizeof(Process) );
    for(int i = 0; i < *lenProcess; i++){
        fscanf(file,"%d %d %d", &((*myProcess)[i].C) , &((*myProcess)[i].D) , &((*myProcess)[i].T) );
    }
}

int* fp_compute(Process* myProcess,int lenProcess,int timeMax){

    int stateProcess[lenProcess] ;
    memset(stateProcess,0,lenProcess);

    //Drawing
    int *tab = malloc(sizeof(int)*timeMax);

    for(int t = 0; t < timeMax ; t++){

        // Check period
        for(int i = 0; i < lenProcess ; i++){
            if(t%myProcess[i].T == 0)
                stateProcess[i] += myProcess[i].C ;
        }

        //Compute 
        for(int i = 0; i < lenProcess+1 ; i++){
            if(i == lenProcess){ //Default case.
                tab[t]=0;
                printf("0 ");
                break;
            }
            else if(stateProcess[i] > 0){
                stateProcess[i]--;
                tab[t] = i+1;
                printf("%d ",i+1);
                break;
            }
        }
    }
    printf("\n");
    return tab;
}

int* edf_compute(Process* myProcess,int lenProcess, int timeMax){

    int *tab = malloc(sizeof(int)*timeMax);

    SortedJobList myJobs = create_empty_list();

    for(int t = 0; t < timeMax ; t++){

        for(int i = 0; i < lenProcess ; i++){
            if(t%myProcess[i].T == 0)
                add_job(&myJobs,i+1,myProcess[i].C,myProcess[i].D);
        }

        tab[t] = schedule_first(&myJobs);
        printf("%d ",tab[t]);    
    
    }
    
    printf("\n");
    free_list(&myJobs);
    return tab;
}