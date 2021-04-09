#include "ordo.h"

typedef Process* Tasksets;



int test_load();
int test_inferior_equal(Tasksets task,int task_lenght);
int test_equal(Tasksets task,int task_lenght);
int isDM(Tasksets task , int task_lenght);
int get_busy_period(Tasksets task, int i);
int get_nb_critical_job(Tasksets task, int i , int bp);
int get_response_time(Tasksets task, int i, int k);
int get_worst_case_response_time(Tasksets task, int i);
int get_response_time_preemptive(Tasksets task, int len, int i, int k);
int get_worst_case_response_time_preemptive(Tasksets task,int len, int i);