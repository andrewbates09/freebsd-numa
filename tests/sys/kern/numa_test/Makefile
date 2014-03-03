# $FreeBSD: head/tests/sys/kern/numa/Makefile 2014-03-03 $

.include <bsd.own.mk>

TESTDIR=	${TESTSBASE}/sys/kern/numa_test

ATF_TESTS_C=	numa_test

SRCS=	cpu_get_memory_affinity_test
SRCS=	cpu_set_memory_affinity_test
SRCS=	move_pages_test
SRCS=	migrate_pages_test
SRCS=	get_numa_cpus_test
SRCS=	get_numa_weights_test

.include <atf.test.mk>