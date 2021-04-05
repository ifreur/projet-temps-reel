#include "ordo.h"

typedef Process* Tasksets;



int test_load();
int test_inferior_equal(Tasksets task,int num);
int test_equal(Tasksets task,int num);
int isDM(Tasksets task , int num);
int get_busy_period(Tasksets task, int i);
int get_nb_critical_job(Tasksets task, int i , int bp);
int get_response_time(Tasksets task, int i, int k);
int get_worst_case_response_time(Tasksets task, int i);