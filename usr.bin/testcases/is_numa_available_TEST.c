/*
 * is_numa_available(): TESTS
 * 
 * Last edited: February 10, 2014
 * By: Andrew Bates
 */


/* ----------- INCLUDES ----------- */

#include "../numanor.h"        /* NUMA USERSPACE */
#include <stdio.h>
#include <assert.h>


/* ---------- DEFINITIONS --------- */


/* 
 * Function Description: is_numa_availiable()
 * Input: void
 * Output: Returns 0 if NUMA is not available, otherwise returns the number of
 *      NUMA nodes as integer.
 * Summary: If this function evaluates as true (1-n nodes), the current machine
 *      is found to have NUMA architecture, and the functions included below
 *      should be available.  If this evaluates to false (0), the current 
 *      machine does not have NUMA architecture, and should not be allowed to
 *      use the following functions. The integer returned is the number of NUMA
 *      nodes available.
 * Prototype: int is_numa_available(void);
 */


/* ---------- TEST PROTOTYPES ----- */

int test_is_numa_available(void);
void tina_run_test(int result, char *testname);

int tina_no_numa_avail(void);
int tina_numa_avail(void);


/* ---------- TEST FUNCTIONS ------ */

// test driver for is_numa_available
// returns total number of failed tests
int test_is_numa_available(void)
{
    int pfail = 0;
    pfail += tina_run_test(tina_no_numa_avail(), "tina_no_numa_avail" );
    pfail += tina_run_test(tina_numa_avail(), "tina_numa_avail" );

    return pfail;
}

// test case comment driver
void tina_run_test(int result, char *testname)
{
    if (result == 0)
    {
        printf("PASSED: test \"%s\"\n", testname);
        return result;
    }
    else
    {
        printf("FAILED: test \"%s\"\n", testname);
        return result;
    }
}

// given that numa is not available
int tina_no_numa_avail(void)
{
    return is_numa_available() == 0 ? 0 : -1;
}

// given that numa is available
int tina_numa_avail(void)
{
    return is_numa_available() > 0 ? 0 : -1;
}