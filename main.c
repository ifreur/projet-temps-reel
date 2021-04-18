#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "worst_case.h"

int main(int argc, char *argv[]){ // File Name, scheduling type, lenght

    if(argc != 4){
        printf("Invalid Parameters \n");
        exit(-1);    
    }

    int time = atoi(argv[3]) ;
    char* type_sched = argv[2] ; 
    char* file_name = argv[1] ;

    int tlen;
    Process* myprocess;
    read_file("input",&myprocess,&tlen);

    edf_compute(myprocess,tlen,time);
/*



    printf("Test Load : %d\n",test_load(&myprocess,tlen));

    for(int j = 1; j <= tlen ; j++){
        printf("-For Process %d -\n",j);

        int busy = get_busy_period(myprocess,j);
        printf("Busy Period: %d \n",busy);

        int nb_criti = get_nb_critical_job(myprocess,j,busy);
        printf("Nb instance : %d \n",nb_criti);
        

    }

    printf("\n\n");

    for(int j = 1; j <= tlen ; j++){
        int wt = get_worst_case_response_time(myprocess,j);
        printf("Worst time %d : %d\n",j,wt);
    }

    printf("\n\n");
        

    for(int j = 1; j <= tlen ; j++){
        int wt = get_worst_case_response_time_preemptive(myprocess,tlen,j);
        printf("Worst time preemptive %d : %d\n",j,wt);
    }
*/
}