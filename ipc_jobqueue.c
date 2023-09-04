/*
 * 200300469
 */
#include "ipc_jobqueue.h"


ipc_jobqueue_t* ipc_jobqueue_new(proc_t* proc) {
    ipc_jobqueue_t* ijq = ipc_new(proc, "ipc_jobq", sizeof(jobqueue_t));
    
    if (!ijq) 
        return NULL;
    
    if (proc->is_init)
        jobqueue_init((jobqueue_t*) ijq->addr);
    
    return ijq;
}

/* 
 * TODO: you must implement this function.
 */

size_t ipc_jobqueue_capacity(ipc_jobqueue_t* ijq) {
	if(ijq){
		return jobqueue_capacity(ijq->addr);
	}
	else{
		return 0;
	}
}

/* 
 * TODO: you must implement this function.
 */

job_t* ipc_jobqueue_dequeue(ipc_jobqueue_t* ijq, job_t* dst) {
	if(ijq){
		return jobqueue_dequeue(ijq->addr, dst);
		do_critical_work(ijq->proc);
	}
    return NULL;
}

/* 
 * TODO: you must implement this function.
 */
void ipc_jobqueue_enqueue(ipc_jobqueue_t* ijq, job_t* job) {
	if(ijq){
		return jobqueue_enqueue(ijq->addr, job);
		do_critical_work(ijq->proc);
	}
	else{
		return NULL;
	}
}
    
/* 
 * TODO: you must implement this function.
 */
bool ipc_jobqueue_is_empty(ipc_jobqueue_t* ijq) {
	if(ijq){
		return jobqueue_is_empty(ijq->addr);
		do_critical_work(ijq->proc);
	}
	else{
		return true;
	}
}

/* 
 * TODO: you must implement this function.
 */
bool ipc_jobqueue_is_full(ipc_jobqueue_t* ijq) {
	if(ijq){
		return jobqueue_is_full(ijq->addr);
		do_critical_work(ijq->proc);
	}
	else{
		return true;
	}
}

/* 
 * TODO: you must implement this function.
 */
job_t* ipc_jobqueue_peekhead(ipc_jobqueue_t* ijq, job_t* dst) {
	if(ijq){
		return jobqueue_peekhead(ijq->addr, dst);
		do_critical_work(ijq->proc);
	}
	else{
		return NULL;
	}
}
    
/* 
 * TODO: you must implement this function.
 */
job_t* ipc_jobqueue_peektail(ipc_jobqueue_t* ijq, job_t* dst) {
	if(ijq){
		return jobqueue_peektail(ijq->addr, dst);
		do_critical_work(ijq->proc);
	}
	else{
	   return NULL;
	}
}

/* 
 * TODO: you must implement this function.
 */
void ipc_jobqueue_delete(ipc_jobqueue_t* ijq) {
	return ipc_delete(ijq);
}
