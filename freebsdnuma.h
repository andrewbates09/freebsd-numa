/*
 * FreeBSD NUMA project
 * The goal of this project is to develop an interface to allow NUMA aware memory allocation
 * from the FreeBSD user-space (expose NUMA functionality). This will involve implementing 
 * syscalls to access NUMA information from userspace and modifying the memory allocator to
 * make allocation decisions based on this information. The indicated APIs should support
 * thread level NUMA domain affinity.
 * 
 * NOTES:
 * Only including header files found in the dir /stable/10/sys/amd64/include/vmparam.h in 
 * the FreeBSD SVN repository. Since the currently involved stakeholders are using Sandy
 * Bridge E5-2620 which use the 64 bit instruction set, we will use amd64 headers for now.
 * FreeBSD notation seems to be <machine/*.h>. Its probably pointing at an environment
 * variable 'machine' to get to the correct machine directory.
 * http://svnweb.freebsd.org/base/stable/10/
 */


#ifndef __FREE_BSD_NUMA_H__
#define __FREE_BSD_NUMA_H__


/* ----------- INCLUDES ----------- */

#include <sys/proc.h>           /* process include */
#include <sys/pcpu.h>           /* included by <sys/proc.h> if _KERNEL not defined */
#include <sys/cpuset.h>
#include </sys/vm/vm_phys.h>
#include <machine/vmparam.h>
#include <malloc.h>             /* Modified version of malloc */


/* ---------- DEFINITIONS --------- */
#define NUMA_NEAREST
#define NUMA_INTERLEAVE
typedef int numa_policy;


/* ------- SYSCALL INTERFACE ------ */


/* Retrieves the memory affinity from the object specified by level, which 
 * and id and returns it as a mask stored in the space provided by mask
 */
int cpuset_get_memory_affinity(cpulevel_t level,
                               cpuwhich_t which,
                               id_t id,
                               size_t setsize,
                               cpuset_t *mask,
                               numa_policy *policy);

/* Sets the memory affinity of the object specified by level,which and id to the value stored in mask */
int cpuset_set_memory_affinity(cpulevel_t level,
                               cpuwhich_t which,
                               id_t id,
                               size_t setsize,
                               cpuset_t *mask,
                               numa_policy *policy);

/* Moves specified pages on specified nodes to new memory nodes. */
long move_pages(int pid,
                unsigned long count,
                void **pages,
                const int *node,
                int *status,
                int flags);

/* Attempts to move all pages of a process in specified nodes to specified new memory nodes. */
int migrate_pages(int pid,
                  unsigned long maxnodesm,
                  const unsigned long *old_nodes,
                  const unsigned long *new_nodes);


#endif /* __FREE_BSD_NUMA_H__ */
