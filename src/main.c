/*!
* \file main.c
* \author Clément Couriol
* \version 0.1
* \date 13/10/2021
* \brief 
* \remarks None
* 
* 
* 
*/

/*! Importation of librairies*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#include "../include/stack.h"
#include "../include/queue.h"
#include "../include/heap.h"

void assert_test_queue();
void cunit_test_queue();
void assert_test_stack();

/*!
* \fn int main(int argc, char **argv)
* \author Clément Couriol
* \version 0.1
* \date 13/10/2021
* \brief Main function of the program
* \remarks None
* \param argc number of arguments given as inputs
* \param *argv
* \return 0 if all went good
*/
int main(int argc, char **argv)
{
    assert_test_queue();

    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    CU_initialize_registry();

    /* add a suite to the registry */
    pSuite = CU_add_suite("Data Structure", NULL, NULL);

    /* add the tests to the suite */
    CU_add_test(pSuite, "test of cunit_test_queue()", cunit_test_queue);

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}

/*!
* \fn void assert_test_queue()
* \author Clément Couriol
* \version 0.1
* \date  14/10/2021
* \brief Unitary test with assert()
* \remarks None
*/
void assert_test_queue()
{
    float a = 1.4, b = 2.4, c = 3.4, d = 6.4, e = 7.4, f = 8.4;
    Queue qu;

    init_queue(&qu);
    assert(qu.index == 0);
    enqueue(&qu, 1.4);
    assert(qu.data[0] == a);
    enqueue(&qu, 2.4);
    assert(qu.data[1] == b);
    enqueue(&qu, 3.4);
    assert(qu.data[2] == c);

    assert(qu.index == 3);

    assert(dequeue(&qu) == a);
    assert(is_queue_empty(&qu) == 0);
    assert(front_queue(&qu) == b);

    clear_queue(&qu);
    assert(qu.index == 0);
    assert(is_queue_empty(&qu) == 1);

    enqueue(&qu, 6.4);
    enqueue(&qu, 7.4);
    enqueue(&qu, 8.4);
    assert(qu.index == 3);
    assert(qu.data[0] == d);
    assert(qu.data[1] == e);
    assert(qu.data[2] == f);
}

/*!
* \fn void cunit_test_queue()
* \author Clément Couriol
* \version 0.1
* \date  14/10/2021
* \brief Unitary test with CUnit
* \remarks None
*/
void cunit_test_queue()
{
    float a = 1.4, b = 2.4, c = 3.4, d = 6.4, e = 7.4, f = 8.4;
    Queue qu;

    init_queue(&qu);
    CU_ASSERT_TRUE_FATAL(qu.index == 0);
    enqueue(&qu, 1.4);
    CU_ASSERT_TRUE_FATAL(qu.data[0] == a);
    enqueue(&qu, 2.4);
    CU_ASSERT_TRUE_FATAL(qu.data[1] == b);
    enqueue(&qu, 3.4);
    CU_ASSERT_TRUE_FATAL(qu.data[2] == c);

    CU_ASSERT_TRUE_FATAL(qu.index == 3);

    CU_ASSERT_EQUAL_FATAL(dequeue(&qu), a);
    CU_ASSERT_EQUAL_FATAL(is_queue_empty(&qu), 0);
    CU_ASSERT_EQUAL_FATAL(front_queue(&qu), b);

    clear_queue(&qu);
    CU_ASSERT_TRUE_FATAL(qu.index == 0);
    CU_ASSERT_EQUAL_FATAL(is_queue_empty(&qu), 1);

    enqueue(&qu, 6.4);
    enqueue(&qu, 7.4);
    enqueue(&qu, 8.4);
    CU_ASSERT_TRUE_FATAL(qu.index == 3);
    CU_ASSERT_TRUE_FATAL(qu.data[0] == d);
    CU_ASSERT_TRUE_FATAL(qu.data[1] == e);
    CU_ASSERT_TRUE_FATAL(qu.data[2] == f);
}

/*!
* \fn void assert_test_stack()
* \author Cédric Gabette
* \version 0.1
* \date  15/10/2021
* \brief Unitary test with assert
* \remarks None
*/
void assert_test_stack()
{
    float a = 1.4, b = 5.2, c = 3.3;

    Stack t0;

    //Initialize the stack : verify if the first index is 0
    init_stack(&t0);
    assert(t0.index == 0);
    //Push 1.4 : verify if index 0 equal to a = 1.4 in float type.
    push_stack(&t0, 1.4);
    assert(t0.data[t0.index - 1] == a);
    //Push 5.2 : verify is index 1 equal to b = 5.2 in float type.
    push_stack(&t0, 5.2);
    assert(t0.data[t0.index - 1] == b);
    //Pop last value : verify if the value on the top of the stack is deleted
    pop_stack(&t0);
    assert(t0.data[t0.index] == 0);
    assert(t0.data[t0.index - 1] == a);
    //Pop et ask if the stack is empty : verify if the only index left is 0
    pop_stack(&t0);
    is_stack_empty(&t0);
    assert(t0.index == 0);
    //Push and duplicate : verify if the last value get duplicate and pushed as the new last value
    push_stack(&t0, 3.3);
    dup(&t0);
    assert(t0.data[t0.index - 2] == c && t0.data[t0.index - 1] == c);
    //Push and swap : verify if the last value goes before last et the before last goes last.
    push_stack(&t0, 1.4);
    swap(&t0);
    assert(t0.data[t0.index - 1] == c && t0.data[t0.index - 2] == a);
    //Clear the stack : verify if the only index left is 0 and if all the values are set to 0
    clear_stack(&t0);
    for (int i = 0; i < STACK_MAX_SIZE; i++)
    {
        assert(t0.data[i] == 0);
    }
    assert(t0.index == 0);
}
