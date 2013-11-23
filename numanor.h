/*
 * FreeBSD NUMA project
 * The goal of this project is to develop an interface to allow NUMA aware
 * memory allocation from the FreeBSD user-space (expose NUMA functionality).
 * This will involve implementing syscalls to access NUMA information from
 * userspace and modifying the memory allocator to make allocation decisions
 * based on this information. The indicated APIs should support thread level
 * NUMA domain affinity.
 * 
 * NOTES:
 * Including header files found in dir /stable/10/sys/amd64/include/vmparam.h in 
 * the FreeBSD SVN repository. Since the currently involved stakeholders are
 * using Sandy Bridge E5-2620 which use the 64 bit instruction set, we will use
 * amd64 headers for now. FreeBSD notation seems to be <machine/*.h>. Its
 * probably pointing at an environment variable 'machine' to get to the correct
 * machine directory. http://svnweb.freebsd.org/base/stable/10/
 */

#ifndef __NUMANOR_H__
#define __NUMANOR_H__


/* ----------- INCLUDES ----------- */

#include <freebsdnuma.h>        /* NUMA syscalls */


/* ---------- DEFINITIONS --------- */


/* ------- USERSPACE LIBRARY ------ */


/* If this returns true, the current machine is has NUMA architecture, and the
 * following functions should be available.  If this returns false, the current
 * machine does not have NUMA architecture, and should not be allowed to use the
 * following functions.
 * NOTE: dependencies on ACPI
 */
int is_numa_available(void);

/* Sets the domain of the designated thread specified by pID to the specified
 * NUMA domain
 */
int set_thread_on_domain(struct thread td,
                         int domain);

/* Set specific memory policy to thread (default action: nearest first touch) */
int set_memory_policy(struct thread td);

/* Move thread to NUMA node and leave associated memory pages estranged */
int move_thread(struct thread td
                int domain);

/* Migrates thread to NUMA node and all the memory pages associated to it */
int migrate_thread(struct thread td
                   int domain);


#endif /* __NUMANOR_H__ */
