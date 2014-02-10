/*
* set_thread_on_domain_TEST.h
* by Dustin Walker
* for NUMAnor
*/
 
/* ****** SUBJECT FUNCTION DESCRIPTION ******
*
* Function: set_thread_on_domain()
* Input:
* int pid: The ID of thread to set on domain.
* int domain: The index of the target NUMA domain.
* Output: Returns 1 on success. Returns 0 on failure.
* Summary: Sets the domain of the designated thread specified by PID to the
* specified NUMA domain.
*
* int set_thread_on_domain(int pid,
*                         int domain);
*/

#ifndef __SET_THREAD_ON_DOMAIN_TEST__H
#define __SET_THREAD_ON_DOMAIN_TEST__H

#define SUCCESS 1
#define FAILURE 0

void test_set_thread_on_domain (void);
void tstod_run_test(int result, char* testname);

int tstod_valid_input (void);
int tstod_negative_pid (void);
int tstod_zero_pid (void);
int tstod_init_pid (void);
int tstod_outofrange_pid (void);
int tstod_negative_domain (void);
int tstod_outofrange_domain (void);

#endif