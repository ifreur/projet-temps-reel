
#include <stdio.h>
#include "sorted_job_list.h"

int main()
{
	int i;
	SortedJobList list = create_empty_list();
	add_job(&list,1,2,8);
	add_job(&list,2,2,6);
	add_job(&list,3,2,7);

	for(i=0;i<10;i++)
		printf("%d ",schedule_first(&list));

	free_list(&list);

	return 0;
}

