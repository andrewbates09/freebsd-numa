/*
* set_thread_on_domain_TEST.c
* by Dustin Walker
* for NUMAnor
*/
 
/* ****** SUBJECT FUNCTION DESCRIPTION ******
*
* Function: set_thread_on_domain()
* Input:
*   int pid:    The ID of thread to set on domain.
*   int domain: The index of the target NUMA domain.
* Output:   Returns 1 on success. Returns 0 on failure.
* Summary:  Sets the domain of the designated thread specified by PID to the
*   specified NUMA domain.
*
* int set_thread_on_domain(int pid,
*                         int domain);
*/

/* ****** SUBJECT FUNCTION DEPENDANCIES ******
* Requires:
*   is_numa_available()
*/

#ifndef __SET_THREAD_ON_DOMAIN_TEST__
#define __SET_THREAD_ON_DOMAIN_TEST__

#include <stdio.h>
#include <assert.h>
#include "numanor.h"
#include "set_thread_on_domain_TEST.h"

#define SUCCESS 1
#define FAILURE 0

void test_set_thread_on_domain (void);
void tstod_run_test(int result, char* testname);

int tstod_valid_input (void);
int tstod_no_numa (void);
int tstod_negative_pid (void);
int tstod_zero_pid (void);
int tstod_init_pid (void);
int tstod_outofrange_pid (void);
int tstod_negative_domain (void);
int tstod_outofrange_domain (void);

//#define NDEBUG

void test_set_thread_on_domain (void)
{
    tstod_run_test( tstod_valid_input(), "tstod_valid_input" );
    tstod_run_test( tstod_no_numa(), "tstod_no_numa" );
    tstod_run_test( tstod_negative_pid(), "tstod_negative_pid" );
    tstod_run_test( tstod_zero_pid(), "tstod_zero_pid" );
    tstod_run_test( tstod_init_pid(), "tstod_init_pid" );
    tstod_run_test( tstod_outofrange_pid(), "tstod_outofrange_pid" );
    tstod_run_test( tstod_negative_domain(), "tstod_negative_domain" );
    tstod_run_test( tstod_outofrange_domain(), "tstod_outofrange_domain" );

    return;
}

void tstod_run_test (int result, char* testname)
{
    if (result == SUCCESS)
    {
        printf("PASSED: test \"%s\"\n", testname);
    }
    else
    {
        printf("FAILED: test \"%s\"\n", testname);
    }
    return;
}

/*
* Function Name: tstod_valid_input
* Pre-Conditions: numa_available = 1 (true)
* Input Parameters: pid    = 2
*                   domain = 1
* Expected Result: 1 (success)
*/
 // I am trying to make this set of test cases more specifically broken up.
int tstod_valid_input (void)
{
    is_numa_available(); // Returns as true.

    if (set_thread_on_domain(2, 1) == SUCCESS)
    {
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

/*
* Function Name: tstod_no_numa
* Pre-Conditions: numa_available = 0 (false)
* Input Parameters: pid    = 2
*                   domain = 1
* Expected Result: 0 (failure)
*/
 // This test case will need to manually change a global
 // numa_available flag in order to trick the system
int tstod_no_numa (void)
{
    is_numa_available(); // Returns as false.

    if (set_thread_on_domain(2, 1) == FAILURE)
    {
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

/*
* Function Name: tstod_negative_pid
* Pre-Conditions: numa_available = 1 (true)
* Input Parameters: pid    = -1
*                   domain = 1
* Expected Result: 0 (failure)
*/
int tstod_negative_pid (void)
{
    is_numa_available(); // Returns as true.

    if (set_thread_on_domain(-1, 1) == FAILURE)
    {
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

/*
* Function Name: tstod_zero_pid
* Pre-Conditions: numa_available = 1 (true)
* Input Parameters: pid    = 0 (kernel process)
*                   domain = 1
* Expected Result: 0 (failure)
*/
int tstod_zero_pid (void)
{
    is_numa_available(); // Returns as true.

    if (set_thread_on_domain(0, 1) == FAILURE)
    {
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

/*
* Function Name: tstod_init_pid
* Pre-Conditions: numa_available = 1 (true)
* Input Parameters: pid    = 1 (init process)
*                   domain = 1
* Expected Result: 0 (failure)
*/
int tstod_init_pid (void)
{
    is_numa_available(); // Returns as true.

    if (set_thread_on_domain(1, 1) == FAILURE)
    {
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

/*
* Function Name: tstod_outofrange_pid
* Pre-Conditions: numa_available = 1 (true)
* Input Parameters: pid    = 1000000000 (hopefully out of range)
*                   domain = 1
* Expected Result: 0 (failure)
*/
int tstod_outofrange_pid (void)
{
    is_numa_available(); // Returns as true.

    if (set_thread_on_domain(1000000000, 1) == FAILURE)
    {
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

/*
* Function Name: tstod_negative_domain
* Pre-Conditions: numa_available = 1 (true)
* Input Parameters: pid    = 2
*                   domain = -1
* Expected Result: 0 (failure)
*/
int tstod_negative_domain (void)
{
    is_numa_available(); // Returns as true.

    if (set_thread_on_domain(2, -1) == FAILURE)
    {
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

/*
* Function Name: tstod_outofrange_domain
* Pre-Conditions: numa_available = 1 (true)
* Input Parameters: pid    = 2
*                   domain = 1000 (hopefully out of range)
* Expected Result: 0 (failure)
*/
int tstod_outofrange_domain (void)
{
    is_numa_available(); // Returns as true.

    if (set_thread_on_domain(2, 1000) == FAILURE)
    {
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

#endif // __SET_THREAD_ON_DOMAIN_TEST__