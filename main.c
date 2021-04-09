#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "worst_case.h"

int main(){
    int tlen;
    Process* myprocess;
    read_file("input",&myprocess,&tlen);
    fp_compute(myprocess,tlen,40);

    printf("%d\n",test_load(myprocess,tlen));

    int bp = get_busy_period(myprocess,1);
    printf("Busy Period 1: %d \n",bp);
    bp = get_busy_period(myprocess,2);
    printf("Busy Period 1: %d \n",bp);
    bp = get_busy_period(myprocess,3);
    printf("Busy Period 1: %d \n",bp);


    int nb_criti = get_nb_critical_job(myprocess,3,40);
    printf("Nb instance : %d \n",nb_criti);

    int tr = get_response_time(myprocess,1,1);
    printf("T rep 1 1 : %d \n",tr);
    tr = get_response_time(myprocess,2,1);
    printf("T rep 2 2 : %d \n",tr);
    tr = get_response_time(myprocess,3,1);
    printf("T rep 3 2 : %d \n",tr);

    int wt = get_worst_case_response_time(myprocess,2);
    printf("Worst time 2 %d\n",wt);

    wt = get_worst_case_response_time(myprocess,1);
    printf("Worst time 1 %d\n",wt);

    wt = get_worst_case_response_time(myprocess,3);
    printf("Worst time 3 %d\n",wt);

    int bt = get_worst_case_response_time_preemptive(myprocess,tlen,2);
    printf("Pre time 2 %d\n",bt);

     bt = get_worst_case_response_time_preemptive(myprocess,tlen,1);
    printf("Pre time 1 %d\n",bt);

     bt = get_worst_case_response_time_preemptive(myprocess,tlen,3);
    printf("Pre time 3 %d\n",bt);


}