#ifndef __FREE_BSD_NUMA_H__
#define __FREE_BSD_NUMA_H__

/*  Notes:
 *  Only including header files found in the dir /stable/10/sys/amd64/include/vmparam.h in the FreeBSD SVN repository.
 *  Since our stakeholders are using Sandy Bridge E5-2620 which use the 64 bit instruction set, we will use amd64 headers for now.
 *  FreeBSD notation seems to be <machine/*.h>. Its probably pointing at an environment variable 'machine' to get to the correct machine directory.
 *  http://svnweb.freebsd.org/base/stable/10/
 */


/* ----------- INCLUDES ----------- */

#include <sys/proc.h> /* process include */
#include <sys/pcpu.h> /* included by <sys/proc.h> if _KERNEL not defined */
#include <sys/cpuset.h>
#include </sys/vm/vm_phys.h>
#include <machine/vmparam.h>
#include <malloc.h> /* Modified version of malloc */


/* ---------- DEFINITIONS --------- */


/* ------- SYSCALL INTERFACE ------ */

// Retrieves the memory affinity from the object specified by level, which and id and returns it as a mask stored in the space provided by mask
int cpuset_get_memory_affinity (cpulevel_t level, cpuwhich_t which, id_t id, size_t setsize, cpuset_t *mask);

// Sets the memory affinity of the object specified by level,which and id to the value stored in mask
int cpuset_set_memory_affinity (cpulevel_t level, cpuwhich_t which, id_t id, size_t setsize, cpuset_t *mask);

// Moves specified pages on specified nodes to new memory nodes.
long move_pages (int pid, unsigned long count, void **pages, const int *node int *status, int flags);

// Attempts to move all pages of a process in specified nodes to specified new memory nodes.
int migrate_pages (int pid, unsigned long maxnodesm, const unsigned long *old_nodes, const unsigned long *new_nodes);


/* ------- USERSPACE LIBRARY ------ */

// If this returns true, the current machine is has NUMA architecture, and the following functions should be avaialable.
// If this returns false, the current machine does not have NUMA architecture, and should not be allowed to use the following functions.
int is_numa_available();

// Returns an int representing the id of the CPU that the specified thread is running on
int get_current_cpu (int pid);

// Retrieves process
struct proc get_current_proc (struct thread td);

// Gets the CPUs in the numa domain specified by the integer domain id.
struct pcpu get_cpus_in_domain (int domain);

// Gets the current domain of the calling thread
int get_current_domain (struct mem_affinity affin);

// Sets the domain of the designated thread specified by pid to the specified numa domain
int set_thread_on_domain (struct thread td, int domain);

// Migrates the memory pages that are NOT located on a thread's assinged NUMA node to its current assigned NUMA node.
int migrate_estranged_pages ();


#endif /* __FREE_BSD_NUMA_H__ */
