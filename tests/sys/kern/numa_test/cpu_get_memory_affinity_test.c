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

 
/* ****** SUBJECT FUNCTION DESCRIPTION ******
 *
 * Function: cpuset_set_memory_affinity()
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
 *
 * struct cpuset_set_memory_affinity_args {
 * 	cpulevel_t	level;
 * 	cpuwhich_t	which;
 * 	id_t		id;
 * 	size_t		setsize;
 * 	cputset_t	*mask;
 * 	int		policy;
 * };
 * 
 * int
 * cpuset_set_memory_affinity(struct cputset_set_memory_affinity_args *uap);
 */

 
/* ----------- INCLUDES ----------- */

#include <sys/numa.h>

#include <errno.h>
#include <stdio.h>

#include <atf-c.h>


/* ---------- DEFINITIONS --------- */

// ATF_CHECK_EQ
// ATF_CHECK
// ATF_CHECK_ERRNO

/* ---------- TEST PROTOTYPES ----- */

ATF_TC_BODY(cpuset_set_memory_affinity_01, tc);


/* ---------- TEST FUNCTIONS ------ */
ATF_TC(cpuset_set_memory_affinity_01);
ATF_TC_HEAD(cpuset_set_memory_affinity_01, tc)
{
	atf_tc_set_md_var(tc, "descr",
	    "Verify success on input.");
}
ATF_TC_BODY(cpuset_set_memory_affinity_01, tc);
{
	cpuset_get_memory_affinity_args test_args;
	test_args.level		= NULL;
	test_args.which		= NULL;
	test_args.id		= NULL;
	test_args.setsize	= NULL;
	(*test_args).mask	= NULL;
	(*test_args).policy	= NULL;
	
	ATF_CHECK(cpuset_set_memory_affinity_01(test_args), == 0)
}


ATF_TC(cpuset_set_memory_affinity_02);
ATF_TC_HEAD(cpuset_set_memory_affinity_02, tc)
{
	atf_tc_set_md_var(tc, "descr",
	    "Verify failure on input.");
}
ATF_TC_BODY(cpuset_set_memory_affinity_02, tc);
{
	cpuset_get_memory_affinity_args test_args;
	test_args.level		= NULL;
	test_args.which		= NULL;
	test_args.id		= NULL;
	test_args.setsize	= NULL;
	(*test_args).mask	= NULL;
	(*test_args).policy	= NULL;
	
	ATF_CHECK(cpuset_set_memory_affinity_02(test_args), == -1)
}

// TEST DRIVER
ATF_TP_ADD_TCS(tp)
{

	ATF_TP_ADD_TC(tp, cpuset_set_memory_affinity_01);
	ATF_TP_ADD_TC(tp, cpuset_set_memory_affinity_02);
	
	return (atf_no_error());
}