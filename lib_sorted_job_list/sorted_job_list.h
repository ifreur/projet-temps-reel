/*
 * Author dm
 */

#ifndef _SORTED_JOB_LIST_H
#define _SORTED_JOB_LIST_H


typedef struct _job{

	int id; /* task id           */
	int rc; /* remaining cost    */
	int d;  /* absolute deadline */

	struct _job * next;

}Job,
*SortedJobList; /* linked list of job */


/* take a list pointer job_list, an id i, a cost c and a deadline d, create a
 * job and add it to the list, sorted by increasing deadlines */
void add_job(SortedJobList * job_list, int i, int c, int d);

/* create and return an empty list of Jobs */
SortedJobList create_empty_list();

/* free the memory used by a list taken as a parameter and assign NULL value to
 * the list (<=> empty list) */
void free_list(SortedJobList* job_list);

/* "schedule" the first job of the list for one time unit and return the
 * associated task id.  Return 0 is the list is empty.  If not, the first job
 * of the list is retrieved, its remaining cost is decreased by 1, and if it
 * reaches 0, the Job is removed from the list (and the associate memory is
 * free).  The function returs either 0 is the list was empty or a positive
 * integer beeing the task id of the first job of the list before the function
 * call.  */
int schedule_first(SortedJobList * job_list);



#endif


