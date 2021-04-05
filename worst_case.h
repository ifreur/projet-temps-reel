#include "ordo.h"

typedef struct Tasksets{
    int len;
    Process* process;
}Tasksets;

int test_load(Tasksets task,int num);
int test_inferior_equal(Process*  task,int num);
int test_equal(Process*  task,int num);
int isDM(Process*  task , int num);
int get_busy_period(Tasksets task, int i);
int get_nb_critical_job(Tasksets task, int i , int bp);
int get_response_time(Tasksets task, int i, int k);
int get_worst_case_response_time(Tasksets task, int i);