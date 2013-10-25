#ifndef __FREE_BSD_NUMA_H__
#define __FREE_BSD_NUMA_H__

/*  Notes:
 *  Only including header files found in the dir /stable/10/sys/amd64/include/vmparam.h in the FreeBSD SVN repository.
 *  Since our stakeholders are using Sandy Bridge E5-2620 which use the 64 bit instruction set, we will use amd64 headers for now.
 *  FreeBSD notation seems to be <machine/*.h>. Its probably pointing at an environment variable 'machine' to get to the correct machine directory.
 *  http://svnweb.freebsd.org/base/stable/10/
 */

/* -------------------------------- */
/* ----------- INCLUDES ----------- */
/* -------------------------------- */

#include <sys/proc.h>
#include <sys/pcpu.h> /* included by <sys/proc.h> if _KERNEL not defined */
#include </sys/vm/vm_phys.h>
#include <machine/vmparam.h>
#include <malloc.h> /* Modified version of malloc */

/* -------------------------------- */
/* ---------- DEFINITIONS --------- */
/* -------------------------------- */

int is_numa_available();
struct pcpu get_current_proc(struct thread thr);
int get_current_domain(struct mem_affinity affinity);
struct mem_affinity* get_memory_affinity(struct pcpu proc);
int set_thread_on_domain (struct thread thr, int domain);

#endif /* __FREE_BSD_NUMA_H__ */
