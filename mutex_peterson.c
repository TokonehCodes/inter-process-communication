/*
 * Replace the following string of 0s with your student number
 * 200300469
 */
#include "mutex_peterson.h"

/* mutex.h contains the specification of functions in this file */

/* 
 * TODO: you must implement this function
 * Hints:
 * - see mutex_lockvar.c for how mutex_new is implemented there but remember
 *      that the underlying mutex type allocated in shared memory and 
 *      encapsulated by the IPC type will be different
 * - the shared object label should be mux_peters
 * - also see: mutex_peterson.h, mutex_lockvar.c and ipc.h
 */
mutex_t* mutex_new(proc_t* proc) {
	return ipc_new(proc, "mux_peters", sizeof(mutex_peterson_t));
}

/* 
 * TODO: you must implement this function.
 * Hints:
 * - see the section on the Peterson's busy waiting solution in 
 *     the CSC2035 lecture material on IPC
 * - process ids must be normalised to either a 0 or 1 for indexing 
 *      into the interested array (there is an arithmetic operator to do this)
 * - remember a mutex_t object is basically an ipc object and the specific
 *      implementation of a mutex (Peterson's in this case) in
 *      shared memory is at the addr field (see ipc.h)
 * - also see: mutex_lockvar.c
 */
void mutex_enter(mutex_t* mux) {
	
	if(!mux){
		return;
	}
	
	mutex_peterson_t* mpt = mux -> addr;
	
	int my_id = (mux->proc->id) % 2;
	int other_id = 1 - my_id;
	
	mpt->interested[my_id] = 1;
	mpt->turn = mux->proc->id;
	
	
	if (mpt->interested[other_id] == 1){
	}
	
    return;
}

/* 
 * TODO: you must implement this function.
 * Hints: see hints for mutex_enter
 */
void mutex_leave(mutex_t* mux) {
	if(!mux){
		return;
	}	
	int turn;
	
	mutex_peterson_t* mpt = mux -> addr;
	int my_id = (mux->proc->id) %2 ;
	int other_id = my_id - 1;
	
	mpt->interested[my_id] = 0;
	mpt->turn = turn;
	
	if (mpt->interested[other_id] == 0){
	}
    return;
}

/* 
 * TODO: you must implement this function.
 * Hint:
 * - deallocate what you allocate in mutex_new
 */
void mutex_delete(mutex_t* mux) {
	free(mux);
    return;
}
