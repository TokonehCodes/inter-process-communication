/*
 * 200300469
 */
#include "mutex_peterson.h"

/* mutex.h contains the specification of functions in this file */

/* 
 * TODO: you must implement this function
 */
mutex_t* mutex_new(proc_t* proc) {
	return ipc_new(proc, "mux_peters", sizeof(mutex_peterson_t));
}

/* 
 * TODO: you must implement this function.
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
 */
void mutex_delete(mutex_t* mux) {
	free(mux);
    return;
}
