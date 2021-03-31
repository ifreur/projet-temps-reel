#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordo.h"

int main(){
    int tlen;
    Process* myprocess;
    read_folder("input",&myprocess,&tlen);
    edf_compute(myprocess,tlen,40);
    
}