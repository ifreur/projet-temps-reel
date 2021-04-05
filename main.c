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
    int bp = get_busy_period(myprocess,3,40);
    printf("Busy Period : %d ",bp);
    int nb_criti = get_nb_critical_job(myprocess,3,40);
    printf("Nb instance : %d ",nb_criti);
    int tr = get_response_time(myprocess,tlen,2,2);
    printf("T rep : %d ",tr);


}