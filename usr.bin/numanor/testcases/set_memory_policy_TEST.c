/*
 * set_memory_policy_TEST.c
 * by Joshua Clark
 * last edited 2/17/2014
 */

 /* ----------- INCLUDES ----------- */
#include <pthread.h>
#include "numanore.h"

/* ---------- DEFINITIONS --------- */
/* 
 * Function: set_memory_policy()
 * Input:
 *     int pid: The ID of thread to set the memory policy for.
 *     int thread_policy: Specifies the thread’s policy, defined in
 *          freebsdnuma.h (NUMA_POLICY_NEAREST, NUMA_POLICY_INTERLEAVE)
 * Output: Returns 1 on success. Returns 0 on failure.
 * Summary: Set specific memory policy to thread (default action: nearest first
 *      touch)
 */
 
 /* ---------- TEST PROTOTYPES ----- */
 int test_self_nearest();
 int test_self_interleave();
 int test_child_nearest();
 int test_child_interleave();
 
 /* ---------- TEST FUNCTIONS ------ */
/* test_self_nearest()
 * checks the return value of set_memory_policy where pid is equal to the current thread
 * and policy is equal to NUMA_POLICY_NEAREST.
*/
int test_self_nearest() {
	int pid = getpid();
	int return_val = set_memory_policy(pid, NUMA_POLICY_NEAREST);
	if(return_val == 1) {
		return 1;
	} else {
		return 0;
	}
}

/* test_self_interleave()
 * checks the return value of set_memory_policy where pid is equal to the current thread
 * and policy is equal to NUMA_POLICY_INTERLEAVE.
*/
int test_self_interleave() {
	int pid = getpid();
	int return_val = set_memory_policy(pid, NUMA_POLICY_INTERLEAVE);
	if(return_val == 1) {
		return 1;
	} else {
		return 0;
	}
}

void loop_thread() {
	while(1);
}

/* test_self_nearest()
 * checks the return value of set_memory_policy where pid is equal to a child thread
 * and policy is equal to NUMA_POLICY_NEAREST.
*/
int test_child_nearest() {
	pthread_t thread;
	pthread_create(&thread, NULL, loop_thread, NULL);
    int return_val = set_memory_policy(thread, NUMA_POLICY_NEAREST);
	if(return_val == 1) {
		return 1;
	} else {
		return 0;
	}
}

/* test_child_interleave()
 * checks the return value of set_memory_policy where pid is equal to a child thread
 * and policy is equal to NUMA_POLICY_INTERLEAVE.
*/
int test_child_interleave() {
	pthread_t thread;
	pthread_create(&thread, NULL, loop_thread, NULL);
	int return_val = set_memory_policy(thread, NUMA_POLICY_INTERLEAVE);
	if(return_val == 1) {
		return 1;
	} else {
		return 0;
	}
}
