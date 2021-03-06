/*
 * FreeBSD NUMA project
 * The goal of this project is to develop an interface to allow NUMA aware
 * memory allocation from the FreeBSD user-space (expose NUMA functionality).
 * This will involve implementing syscalls to access NUMA information from
 * userspace and modifying the memory allocator to make allocation decisions
 * based on this information. The indicated APIs should support thread level
 * NUMA domain affinity.
 * 
 * Last Edited: February 08, 2014
 */


/* ----------- INCLUDES ----------- */
#include <sys/cdefs.h>

#include <asm/uaccess.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/systm.h>
#include <sys/sysproto.h>
#include <sys/jail.h>
#include <sys/kernel.h>
#include <sys/lock.h>
#include <sys/malloc.h>
#include <sys/mutex.h>
#include <sys/priv.h>
#include <sys/proc.h>
#include <sys/refcount.h>
#include <sys/sched.h>
#include <sys/smp.h>
#include <sys/syscallsubr.h>
#include <sys/cpuset.h>
#include <sys/sx.h>
#include <sys/queue.h>
#include <sys/libkern.h>
#include <sys/limits.h>
#include <sys/bus.h>

#include <sys/freebsdnuma.h>


/* ---------- DEFINITIONS --------- */


/* ------- SYSCALL INTERFACE ------ */

/* Function: cpuset_get_memory_affinity()
 * Input:
 *      cpulevel_t level: Specifies the level for the operation (root, cpuset or
 *          which).
 *      cpuwhich_t which: Defines the type of object denoted by id_t (TID, PID,
 *          IRQ, or CPUSET).
 *      id_t id: The id of the object
 *      size_t setsize: The size of the set.
 *      cpuset_t *mask: specifies the address to be filled with mask of NUMA
 *          nodes with affinity.
 *      int *policy: Specifies the address to store the value of the NUMA memory
 *          policy of the specified object.
 * Output: Returns 0 for success. Returns -1 for failure.
 * Summary: Used to retrieve the memory affinity and allocation policy from the
 *      object specified by level, which, and id and returns it as a cpuset
 *      stored in the space provided by mask. Also retrieves the memory
 *      allocation policy of the specified object and stores the value in policy
 */
int 
sys_cpuset_get_memory_affinity(struct thread *td, struct cpuset_get_memory_affinity_args *uap)
{
    struct cpuset_get_memory_affinity_args * argsptr;
    unsigned long bytes_not_copied;

    //get args from userspace
    argsptr = (*cpuset_get_memory_affinity_args) kmalloc(sizeof(cpuset_get_memory_affinity_args));
    bytes_not_copied = copy_from_user(argsptr,uap,sizeof(cpuset_get_memory_affinity_args));
    
    //check to make sure we got everything
    if (bytes_not_copied > 0)
    {
        //some bytes weren't copied, bail
        return 89;
    }

    //data validation for cpulevel_t
    if ((argsptr->level > 3) || (argsptr->cpulevel < 1))
    {
        //invalid level; return errno 33
        return 33;
    }

    //data validation for cpuwhich_t
    if ((argsptr->cpuwhich > 5) || (argsptr->cpuwhich < 1))
    {
        //invalid which; return errno 33
        return 33;
    }

    return 0;
}

/* Function: cpuset_set_memory_affinity()
 * Input:
 *      cpulevel_t level: Specifies the level for the operation (root, cpuset or
 *          which).
 *      cpuwhich_t which: Defines the type of object defined by id_t (TID, PID,
 *          IRQ, or CPUSET).
 *      id_t id: The id of the object type specified by which.
 *      size_t setsize: The size of the set.
 *      const cpuset_t *mask: specifies the address to be filled with mask of
 *          NUMA nodes with affinity.
 *      int policy: Defines the NUMA memory policy of the specified object.
 * Output: Returns 0 for success. Returns -1 for failure.
 * Summary: Sets the memory affinity and allocation policy of the object
 *      specified by level,which and id to the value stored in mask and policy.
 */
int 
sys_cpuset_set_memory_affinity(struct thread *td, struct cpuset_set_memory_affinity_args *uap)
{
    struct cpuset_set_memory_affinity_args * argsptr;
    unsigned long bytes_not_copied;
    //get args from userspace
    argsptr = (*cpuset_set_memory_affinity_args) kmalloc(sizeof(cpuset_set_memory_affinity_args));
    bytes_not_copied = copy_from_user(argsptr,uap,sizeof(cpuset_set_memory_affinity_args));
    
    //check to make sure we got everything
    if (bytes_not_copied > 0)
    {
        //some bytes weren't copied, bail
        return 89;
    }

    //data validation for cpulevel_t
    if ((argsptr->level > 3) || (argsptr->cpulevel < 1))
    {
        //invalid level; return errno 33
        return 33;
    }

    //data validation for cpuwhich_t
    if ((argsptr->cpuwhich > 5) || (argsptr->cpuwhich < 1))
    {
        //invalid which; return errno 33
        return 33;
    }

    return 0;
}


/* Function: move_pages()
 * Input:
 *      int pid: Specifies the process ID of the pages to be moved. 0 refers to
 *          the calling process.
 *      unsigned long count: The number of pages to move. Defines the size of
 *          the arrays pages, node, and status.
 *      const int *node: An array of integers specifying the desired node
 *          location for each page.
 *      void ** pages: An array of the pages to be moved.
 *      int * status: An array of integers giving the status of each page.
 *      int move_flag: An integer to specify whether memory that is shared with
 *          other processes is also to be moved (NUMA_MOVE or NUMA_MOVE_ALL).
 * Output: Returns 0 for success.  Returns -1 for failure.
 * Summary: Used to move specific pages on specified nodes to new NUMA nodes.
 */
int 
sys_move_pages(struct thread *td, struct move_pages_args *uap)
{
    return 0;
}

/* Function: migrate_pages()
 * Input:
 *      int pid: The process ID of the pages to be moved. 0 refers to the
 *          calling process.
 *      unsigned long maxnode: The size of the node bitmasks.
 *      const unsigned long *old_nodes: The bitmask representing the old nodes.
 *      const unsigned long *new_nodes: The bitmask representing the new nodes.
 * Output: Returns 0 for success.  Returns -1 for failure.
 * Summary: Attempts to move all pages of a process in specified nodes to
 *      specified new NUMA nodes.
 */
int
sys_migrate_pages(struct thread *td, struct migrate_pages_args *uap)
{
    return 0;
}
 
/* Function: get_numa_cpus()
 * Input:
 *      cpuset_t *buff: An array to be filled with cpusets.
 *      size_t length: The length of the array in bytes.
 * Output: Returns the count of NUMA nodes and fills buff with an array of
 *      cpusets. Passing a null buff and length of 0 will simply return the
 *      count of NUMA nodes.
 * Summary: Allows processes to know what cpus belong to each NUMA node. This is
 *      useful in assigning memory affinity and policies. 
 */
int 
sys_get_numa_cpus(struct thread *td, struct get_numa_cpus_args *uap)
{
    return 0;
}

/* Function: get_numa_weights()
 * Input:
 *      short *buff: A 2d array to be filled with weights between nodes, where
 *          the indexes are relative IDs.
 *      size_t length: The length of the array in bytes.
 * Output: Returns the count of NUMA nodes and fills buff with a 2 dimensional
 *      array of weights between NUMA nodes. Passing a null buff and length of 0
 *      will simply return the count of NUMA nodes.
 * Summary: Allows processes to know about relative latency between NUMA nodes. 
 *      Weight between two NUMA nodes can be found by accessing the value at
 *      buff[a][b] where a and b are memory node IDs.
 */
int
sys_get_numa_weights(struct thread *td, struct get_numa_weights_args *uap)
{
	int fail;
	short *domain_map;
	if(uap->length < vm_ndomains * vm_ndomains)
	{
		// Not enough space
		return (vm_ndomains);
	}

	domain_map = (*short)kmalloc(sizeof(short) * vm_domains * vm_domains);

	if(!domain_map) // Cannot allocate memory
	{
		return (vm_ndomains);
	}

	for(int i = 0; i < vm_ndomains; i++)
	{
		for(int j = 0, j < vm_ndomains, j++)
		{
			// Fill with sample data	
			if(i == j)
			{
				domain_map[i][j] = 0;
			}
			else
			{
				domain_map[i][j] = 1;
			}
		}
	}
	
	// Copy memory to userspace
	fail = copy_to_user(uap->buff, domain_map, sizeof(short) * vm_domains * vm_domains);

	// if(fail) // unable to copy to userspace
	free(domain_map);

	return (vm_ndomains);
}
