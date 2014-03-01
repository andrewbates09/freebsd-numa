/*
 * move_thread(): TESTS
 * 
 * Last edited: March 01, 2014
 * By: NUMAnor
 */
 
/* ****** SUBJECT FUNCTION DESCRIPTION ******
 * Function: move_thread()
 * Input: 
 *     int pid: The ID of thread to move.
 *     int domain: The ID of NUMA domain to move to.
 *     int mem_flag: Specify the memory action for moving a thread (MEM_LEAVE
 *          MEM_MIGRATE).
 * Output: Returns 1 on success. Returns 0 on failure.
 * Summary: Moves a thread to a specified NUMA node and sets memory allocation
 *      preferences to the specified NUMA domain. Memory pages are either left 
 *      estranged or migrated, depending on policy defined by mem_flag.
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


/* ---------- TEST FUNCTIONS ------ */

