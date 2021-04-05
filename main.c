#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "worst_case.h"

int main(){
    int tlen;
    Process* myprocess;
    read_file("input",&myprocess,&tlen);
    //edf_compute(myprocess,tlen,40);

    Tasksets task_ = {tlen,myprocess};

    printf("%d\n",test_load(task_,tlen));

    int bp = get_busy_period(task_,1);
    printf("Busy Period 1: %d \n",bp);
    bp = get_busy_period(task_,2);
    printf("Busy Period 1: %d \n",bp);
    bp = get_busy_period(task_,3);
    printf("Busy Period 1: %d \n",bp);


    int nb_criti = get_nb_critical_job(task_,3,40);
    printf("Nb instance : %d \n",nb_criti);
    int tr = get_response_time(task_,2,2);
    printf("T rep : %d \n",tr);


}