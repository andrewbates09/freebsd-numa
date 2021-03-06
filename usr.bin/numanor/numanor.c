/*-
 * Copyright (c) 2014 EMC Corporation 
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $FreeBSD$
 */

/*
 * FreeBSD NUMA project - userspace
 * 
 * The numanor.h userspace library takes advantage of NUMA functionality exposed
 * by the freebsdnuma.h syscalls.  In short, this abstracts the syscalls
 * included in freebsdnuma.h and makes them more user friendly.  Users should be
 * able to make their application NUMA-aware by using these functions.  Also
 * included are basic functions to test NUMA.
 * 
 * Last Edited: February 08, 2014
 */


/* ----------- INCLUDES ----------- */

#include <sys/param.h>
#include <sys/freebsdnuma.h>        /* NUMA syscalls */


/* ---------- DEFINITIONS --------- */


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
int
is_numa_available(void)
{

	return (0);
}

/* 
 * Function: set_thread_on_domain()
 * Input:
 *     pid_t pid: The ID of thread to set on domain.
 *     int domain: The index of the target NUMA domain.
 * Output: Returns 1 on success. Returns 0 on failure.
 * Summary: Sets the domain of the designated thread specified by PID to the
 *      specified NUMA domain.
 */
int
set_thread_on_domain(pid_t pid, int domain)
{

	return (0);
}

/* 
 * Function: set_memory_policy()
 * Input:
 *     pid_t pid: The ID of thread to set the memory policy for.
 *     int thread_policy: Specifies the thread’s policy, defined in
 *          freebsdnuma.h (NUMA_POLICY_NEAREST, NUMA_POLICY_INTERLEAVE)
 * Output: Returns 1 on success. Returns 0 on failure.
 * Summary: Set specific memory policy to thread (default action: nearest first
 *      touch)
 */
int set_memory_policy(pid_t pid, int thread_policy)
{

	return (0);
}

/* 
 * Function: move_thread()
 * Input: 
 *     pid_t pid: The ID of thread to move.
 *     int domain: The ID of NUMA domain to move to.
 *     int mem_flag: Specify the memory action for moving a thread (MEM_LEAVE
 *          MEM_MIGRATE).
 * Output: Returns 1 on success. Returns 0 on failure.
 * Summary: Moves a thread to a specified NUMA node and sets memory allocation
 *      preferences to the specified NUMA domain. Memory pages are either left 
 *      estranged or migrated, depending on policy defined by mem_flag.
 */
int
move_thread(pid_t pid, int domain, int mem_flag)
{

	return (0);
}

int
main(void)
{

	return (0);
}
