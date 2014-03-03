/*
 * move_thread(): TESTS
 * 
 * Last edited: March 01, 2014
 * By: NUMAnor
 */
 
/* ****** SUBJECT FUNCTION DESCRIPTION ******
 * Function: move_thread()
 * Input: 
 *     int pid: The ID of thread to move.
 *     int domain: The ID of NUMA domain to move to.
 *     int mem_flag: Specify the memory action for moving a thread (MEM_LEAVE
 *          MEM_MIGRATE).
 * Output: Returns 1 on success. Returns 0 on failure.
 * Summary: Moves a thread to a specified NUMA node and sets memory allocation
 *      preferences to the specified NUMA domain. Memory pages are either left 
 *      estranged or migrated, depending on policy defined by mem_flag.
 */

/* ****** SUBJECT FUNCTION DEPENDANCIES ******
 * Requires:
 * 	
 */

/* ----------- INCLUDES ----------- */

#include "../numanor.h"		/* NUMA USERSPACE */
#include <stdio.h>


/* ---------- DEFINITIONS --------- */


/* ---------- TEST PROTOTYPES ----- */

int test_valid_move();
int test_valid_selfmove();
int test_invalid_move();
int test_migrate_thread();


/* ---------- TEST FUNCTIONS ------ */

//tests if a valid move to domain 1 will work
int test_valid_move()
{
    int pid;
    char* bigpages;
    pid = fork();
    if (pid<0)
    {
        //fork failed, return 0
        return 0;
    }
    else if (pid)
    {
        wait(&pid);
        move_thread(pid,1,MEM_LEAVE);
        if (1) //the thread was moved successfully
        {
            kill(pid);
            return 1;
        }
        else if (1) //the thread'd memory pages were moved
        {
            kill(pid);
            return 0;
        }
        else
        {
            kill(pid);
            return 0;
        }

    }
    else
    {
        //allocate 4k for pages
        bigpages = (char*)malloc(sizeof(char)*4096);
        //signal the parent that we have finished allocation
        wake(&pid)
        pause();
    }

}

//tests an invalid move
int test_invalid_move()
{
    int pid,status;
    pid = getpid();
    status = move_thread(pid,999,MEM_MIGRATE);
    if (status == 0)
        return 1;
    else
        return 0;
}

//tests a self move of a thread
int test_valid_selfmove()
{
    int pid,status;
    char* bigpages;

    pid = getpid();
    bigpages = (char*) malloc(sizeof(char)*4096);
    status = move_thread(pid,1,MEM_MIGRATE);
    if (status == 0)
    {
        //move failed, return 0
        return 0;
    }
    
    if (1)//test if the thread is on domain one
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

//tests if a valid migrate to domain 1 will work
int test_valid_move()
{
    int pid;
    char* bigpages;
    pid = fork();
    if (pid<0)
    {
        //fork failed, return 0
        return 0;
    }
    else if (pid)
    {
        wait(&pid);
        move_thread(pid,1,MEM_MIGRATE);
        if (1) //the thread was moved successfully and the thread's pages
        { //were moved
            kill(pid);
            return 1;
        }
        else
        {
            kill(pid);
            return 0;
        }

    }
    else
    {
        //allocate 4k for pages
        bigpages = (char*)malloc(sizeof(char)*4096);
        //signal the parent that we have finished allocation
        wake(&pid)
        pause();
    }

}


