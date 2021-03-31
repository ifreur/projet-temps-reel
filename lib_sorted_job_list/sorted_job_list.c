#include <stdlib.h>
#include <stdio.h>
#include "sorted_job_list.h"



void add_job(SortedJobList * job_list, int i, int c, int d){

	Job * tmp;
	/* creation d'un nouveau job */
	Job *j = (Job*) malloc(sizeof(Job));
	if(j==NULL){perror("allocation failed"); exit(1);}

	j->id=i;
	j->rc=c;
	j->d=d;
	j->next=NULL;

	/* Si liste est vide, la liste devient le job */
	if(*job_list == NULL)
	{
		*job_list = j;
		return;
	}

	/* si le premier job a une d plus grande, insertion en tete */
	if((*job_list)->d > d){
		j-> next = *job_list;
		*job_list = j;
		return ;
	}

	/* recherche du precedant dans la liste */
	for(tmp=*job_list ; tmp->next!=NULL && tmp->next->d <= d; tmp=tmp->next)
		; 

	/* le suivant du nouveau Job devient le suivant du précedant */
	j->next = tmp->next;
	/* l suivant du précédant devient le nouveau Job */
	tmp-> next = j;


}

SortedJobList create_empty_list(){
	return NULL;
}

void free_list(SortedJobList* job_list){
	if(job_list==NULL)return;
	while(*job_list!=NULL){ /* tant que la liste n'est pas vide */
		Job* next_job = (*job_list)->next; /* sauvegarde du second Job */
		free(*job_list); /* libération de la mémoire associé au premier Job */
		*job_list=next_job; /* la liste devient le second Job */
	}

}

int schedule_first(SortedJobList * job_list){

	/* La valeur a renvoyer est soit 0 si la liste est vide, soit l'id de
	 * la tache associé au premier Job de la liste */
	int v = (*job_list==NULL)? 0 : (*job_list)->id;

	if(v!=0){/* Si la liste n'était pas vide */
		/* diminution du temps de calcul restant */
		(*job_list)->rc--;
		if((*job_list)->rc == 0){ /* si le temps calcul restant passe à 0, suppression du Job */
			Job * tmp = *job_list; /* sauvegarde du premier Job */
			*job_list = tmp->next; /* la tete de liste devient le second job */
			free(tmp); /* la mémoire associée a l'ancien premier Job est libérée */
		}
	}
	return v;


}


