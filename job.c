/*
 * 200300469
 */
#include <stdlib.h>
#include <stdio.h>
#include "job.h"



/* 
 * DO NOT EDIT the job_new function.
 */
job_t* job_new(pid_t pid, unsigned int id, const char* label) {
    return job_set((job_t*) malloc(sizeof(job_t)), pid, id, label);
}

/* 
 * TODO: you must implement this function
 * Hint:
 * - look for other functions in this file that you can use to implement 
 *      this function
 */
job_t* job_copy(job_t* dst, job_t* src) {
	if (src==NULL){
		return NULL;
	}
	if (src == NULL){
		return src;
	}
	if (dst==NULL){
		return job_new(src->pid, src->id, src->label);
	}
	if (dst && dst!=src){
		return job_set(dst, src->pid, src->id, src->label);
	}
	return dst;
}

/* 
 * TODO: you must complete the implementation of this function, which 
 * currently only sets the pid and id fields of a job to zero.
 */
void job_init(job_t* job) {
	if(job == NULL){
		return NULL;
	}
    job->pid = 0;
    job->id = 0;
	memset(job->label, 0, MAX_NAME_SIZE);
}

/* 
 * TODO: you must complete the implementation of this function, which 
 * currently only compares the pid and id fields of a job.
 */
bool job_is_equal(job_t* j1, job_t* j2) {
	if (j1 == NULL && j2 == NULL){
		return true;
	}
	if (j2 == NULL || j1 == NULL){
		return false;
	}
    return j1->pid == j2->pid && j1->id == j2->id 
	        && !strncmp(j1->label, j2->label, MAX_NAME_SIZE - 1);
}

/*
 * TODO: you must implement this function.
 * Hint:
 * - read the information in job.h about padding and truncation of job labels
 */
job_t* job_set(job_t* job, pid_t pid, unsigned int id, const char* label) {
	if (job == NULL){
		return job;
	}
	
	job->pid = pid;
    job->id = id;
	char* labstr = job->label;
	
	char* padlabel[MAX_NAME_SIZE];
	memset(&padlabel, PAD_CHAR, MAX_NAME_SIZE -1);
	padlabel[MAX_NAME_SIZE - 1] = '\0';
		
	//add if statement for if there is a label at all.
	//if there is, do padding, if not, just put PAD_CHAR
	if(label){
		snprintf(labstr, MAX_NAME_SIZE, "%s%s", label, padlabel);
	}
	else{
		snprintf(labstr, MAX_NAME_SIZE, "%s", padlabel);
	}

    return job;
}

/* 
 * TODO: you must implement this function
 * Hint:
 * - look at the allocation of a job in job_new
 */
void job_delete(job_t* job) {
	free (job);
}
