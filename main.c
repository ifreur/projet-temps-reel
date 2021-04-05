#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "worst_case.h"

int main(){
    int tlen;
    Process* myprocess;
    read_file("input",&myprocess,&tlen);
    //edf_compute(myprocess,tlen,40);

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


}