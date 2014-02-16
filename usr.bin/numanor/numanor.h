/*
 * FreeBSD NUMA project - userspace
 * 
 * The numanor.h userspace library takes advantage of NUMA functionality exposed
 * by the freebsdnuma.h syscalls.  In short, this abstracts the syscalls
 * included in freebsdnuma.h and makes them more user friendly.  Users should be
 * able to make their application NUMA-aware by using these functions.  Also
 * included are basic functions to test NUMA.
 * 
 * Last Edited: December 08, 2013
 */

#ifndef __NUMANOR_H__
#define __NUMANOR_H__


/* ----------- INCLUDES ----------- */

#include <sys/freebsdnuma.h>        /* NUMA syscalls */


/* ---------- DEFINITIONS --------- */

/* 
 * numa_count: The number of distinct NUMA nodes on the system.
 * numa_cpus: An array of cpuset structs that denotes the number of distinct
 *      NUMA CPUs. See get_numa_cpus() in freebsdnuma.h.
 * numa_weights: A 2 dimensional array of shorts to store weights. See
 *      get_numa_weights() in freebsdnuma.h.
 * Summary: The NUMA count, cpus, and weight will be set by is_numa_available()
 *      and are available for other userspace functions.
 */
extern size_t numa_count;
extern cpuset_t *numa_cpus;
extern uint16_t *numa_weights;

/*
 * MEM_LEAVE: When moving a thread, leaves all associated memory pages estranged
 * MEM_MIGRATE: When moving a thread, migrates all associated memory pages to
 *      the specified NUMA domain.
 * Summary: The MEM flags specify the behaviour of move_thread()
 */
#define MEM_LEAVE       1
#define MEM_MIGRATE     2


/* ---------- USERSPACE LIBRARY --- */

/* 
 * Function: is_numa_availiable()
 * Input: void
 * Output: Returns 0 if NUMA is not available, otherwise returns the number of
 *      NUMA nodes as integer.
 * Summary: If this function evaluates as true (1-n nodes), the current machine
 *      is found to have NUMA architecture, and the functions included below
 *      should be available.  If this evaluates to false (0), the current 
 *      machine does not have NUMA architecture, and should not be allowed to
 *      use the following functions. The integer returned is the number of NUMA
 *      nodes available.
 */
int is_numa_available(void);

/* 
 * Function: set_thread_on_domain()
 * Input:
 *     int pid: The ID of thread to set on domain.
 *     int domain: The index of the target NUMA domain.
 * Output: Returns 1 on success. Returns 0 on failure.
 * Summary: Sets the domain of the designated thread specified by PID to the
 *      specified NUMA domain.
 */
int set_thread_on_domain(int pid,
                         int domain);

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
int set_memory_policy(int pid,
                      int thread_policy);

/* 
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
int move_thread(int pid,
                int domain,
                int mem_flag);


#endif /* __NUMANOR_H__ */
