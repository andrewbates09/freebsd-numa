#ifndef __FREE_BSD_NUMA_H__
#define __FREE_BSD_NUMA_H__

/*	Notes:
 * 	Only including header files found in the dir /stable/10/sys/amd64/include/vmparam.h in the FreeBSD SVN repository.
 *	Since our stakeholders are using Sandy Bridge E5-2620 which use the 64 bit instruction set, we will use amd64 headers for now.
 *	FreeBSD notation seems to be <machine/*.h>. Its probably pointing at an environment variable 'machine' to get to the correct machine directory.
 *	http://svnweb.freebsd.org/base/stable/10/
 */

/* -------------------------------- */
/* ----------- INCLUDES ----------- */
/* -------------------------------- */

#include <sys/proc.h> /* process include */
#include <sys/pcpu.h> /* included by <sys/proc.h> if _KERNEL not defined */
#include </sys/vm/vm_phys.h>
#include <machine/vmparam.h>
#include <malloc.h> /* Modified version of malloc */

/* -------------------------------- */
/* ---------- DEFINITIONS --------- */
/* -------------------------------- */

/* ------- SYSCALL INTERFACE ------ */

struct mem_affinity* get_memory_affinity (struct pcpu cpu);
void set_memory_affinity (struct pcpu cpu, int domain);
// Moves specified pages on specified nodes to new memory nodes.
int move_pages ();
// Attempts to move all pages of a process in specified nodes to specified new memory nodes.
int migrate_pages ();

/* ------- USERSPACE LIBRARY ------ */

// If this returns true, the current machine is has NUMA architecture, and the following functions should be avaialable.
// If this returns false, the current machine does not have NUMA architecture, and should not be allowed to use the following functions.
int is_numa_available();
struct proc get_current_proc (struct thread td);
struct pcpu get_cpus_in_domain (int domain);
int get_current_domain (struct mem_affinity affin);
int set_thread_on_domain (struct thread td, int domain);
// Migrates the memory pages that are NOT located on a thread's assinged NUMA node to its current assigned NUMA node.
int migrate_estranged_pages ();

#endif /* __FREE_BSD_NUMA_H__ */