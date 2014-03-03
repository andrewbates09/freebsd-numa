# $FreeBSD: head/tests/sys/kern/Makefile 261081 2014-03-03 10:00:00pst numanor $

.include <bsd.own.mk>

TESTSDIR=	${TESTSBASE}/sys/kern

ATF_TESTS_C=	unix_seqpacket_test
TEST_METADATA.unix_seqpacket_test+=	timeout="15"

ATF_TESTS_SUBDIRS+= numa_test

LDADD+=		-lpthread

.include <atf.test.mk>