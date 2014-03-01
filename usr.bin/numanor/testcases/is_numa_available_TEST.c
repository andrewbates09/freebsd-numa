/*
 * is_numa_available(): TESTS
 * 
 * Last edited: March 01, 2014
 * By: NUMAnor
 */

/* ****** SUBJECT FUNCTION DESCRIPTION ******
 *
 * Function Description: is_numa_availiable()
 * Input: void
 * Output: Returns 0 if NUMA is not available, otherwise returns the number of
 *	NUMA nodes as integer.
 * 	size_t numa_count: 
 * 	cpuset_t *numa_cpus: 
 * 	uint16_t * numa_weights: 
 * Summary: If this function evaluates as true (1-n nodes), the current machine
 * 	is found to have NUMA architecture, and the functions included below
 * 	should be available.  If this evaluates to false (0), the current 
 * 	machine does not have NUMA architecture, and should not be allowed to
 * 	use the following functions. The integer returned is the number of NUMA
 * 	nodes available.
 *	N
 * Prototype: int is_numa_available(void);
 */

/* ****** SUBJECT FUNCTION DEPENDANCIES ******
 * Requires:
 * 	
 */

/* ----------- INCLUDES ----------- */

#include "../numanor.h"		/* NUMA USERSPACE */
#include <stdio.h>


/* ---------- DEFINITIONS --------- */


/* ---------- TEST PROTOTYPES ----- */

int test_is_numa_available(void);
void tina_run_test(int result, char *testname);

int tina_no_numa_available(void);
int tina_numa_available(void);


/* ---------- TEST FUNCTIONS ------ */

/*
 * Function: test_is_numa_available()
 * Pre-Conditions:
 * Input Parameters: void
 * Expected Result: 0 (success)
 * Summary: Test driver for is_numa_available().  Returns total number of failed
 * 	tests.
 */
int
test_is_numa_available(void)
{
	int pfail = 0;
	pfail += tina_run_test(tina_no_numa_available(), "tina_no_numa_avail" );
	pfail += tina_run_test(tina_numa_available(), "tina_numa_avail" );

	return (pfail);
}

/*
 * Function: tina_run_test()
 * Pre-Conditions:
 * Input Parameters:
 *	int result: 0 for success, else failure
 *	char *testname: test name to display pass/failure
 * Expected Result: void
 * Summary: Test case comment driver.
 */
void
tina_run_test(int result, char *testname)
{
	if (result == 0)
	{
		printf("PASSED: test \"%s\"\n", testname);
		return (result);
	}
	else
	{
		printf("FAILED: test \"%s\"\n", testname);
		return (result);
	}
}

/*
 * Function: tina_no_numa_available()
 * Pre-Conditions: NUMA is not physically available.
 * Input Parameters:
 * 	int avail: The 
 * Expected Result: 0 for success. -1 for failure.
 * Summary: Given that NUMA is not available, should resolve as 0.
 */
int
tina_no_numa_available(int avail)
{
	int check;
	check = (is_numa_available() == avail ? 0 : -1);
	return (check);
}

/*
 * Function: tina_numa_available()
 * Pre-Conditions: NUMA is physically available.
 * Input Parameters:
 * 	int avail:
 * Expected Result: 0 for success. -1 for failure.
 * Summary: Given that NUMA is available, should resolve as 0.
 */
int
tina_numa_available(int avail)
{
	int check;
	check = (is_numa_available() == avail ? 0 : -1);
	return (check);
}