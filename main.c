#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "worst_case.h"

int main(){
    int tlen;
    Process* myprocess;
    read_file("input",&myprocess,&tlen);
    edf_compute(myprocess,tlen,40);
    printf("%d\n",test_load(myprocess,tlen));
}