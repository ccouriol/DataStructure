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
#include "../include/array_list.h"
#include "../include/queue.h"
#include "../include/heap.h"

void assert_test_queue();
void assert_test_stack();
void assert_test_arraylist();
void assert_test_heap();
void cunit_test_queue();
void cunit_test_stack();
void cunit_test_arraylist();
void cunit_test_heap();

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
    assert_test_stack();
    assert_test_arraylist();
    assert_test_heap();

    CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    CU_initialize_registry();

    /* add a suite to the registry */
    pSuite = CU_add_suite("Data Structure", NULL, NULL);

    /* add the tests to the suite */
    CU_add_test(pSuite, "test of cunit_test_queue()", cunit_test_queue);
    CU_add_test(pSuite, "test of cunit_test_stack()", cunit_test_stack);
    CU_add_test(pSuite, "test of cunit_test_arraylist()", cunit_test_arraylist);
    CU_add_test(pSuite, "test of cunit_test_heap()", cunit_test_heap);

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
    float toreturn = pop_stack(&t0);
    assert(toreturn == b);
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

/*!
* \fn void cunit_test_stack()
* \author GABETTE Cédric
* \version 0.1
* \date  15/10/2021
* \brief Unitary test with CUnit
* \remarks None
*/
void cunit_test_stack()
{

    float a = 1.4, b = 5.2, c = 3.3;

    Stack t0;

    //Initialize the stack : verify if the first index is 0
    init_stack(&t0);
    CU_ASSERT_TRUE_FATAL(t0.index == 0);
    //Push 1.4 : verify if index 0 equal to a = 1.4 in float type.
    push_stack(&t0, 1.4);
    CU_ASSERT_TRUE_FATAL(t0.data[t0.index - 1] == a);
    //Push 5.2 : verify is index 1 equal to b = 5.2 in float type.
    push_stack(&t0, 5.2);
    CU_ASSERT_TRUE_FATAL(t0.data[t0.index - 1] == b);
    //Pop last value : verify if the value on the top of the stack is deleted
    pop_stack(&t0);
    CU_ASSERT_EQUAL_FATAL(pop_stack(&t0), a);
    //Pop et ask if the stack is empty : verify if the only index left is 0
    pop_stack(&t0);
    is_stack_empty(&t0);
    CU_ASSERT_TRUE_FATAL(t0.index == 0);
    //Push and duplicate : verify if the last value get duplicate and pushed as the new last value
    push_stack(&t0, 3.3);
    dup(&t0);
    CU_ASSERT_TRUE_FATAL(t0.data[t0.index - 2] == c && t0.data[t0.index - 1] == c);
    //Push and swap : verify if the last value goes before last et the before last goes last.
    push_stack(&t0, 1.4);
    swap(&t0);
    CU_ASSERT_TRUE_FATAL(t0.data[t0.index - 1] == c && t0.data[t0.index - 2] == a);
    //Clear the stack : verify if the only index left is 0 and if all the values are set to 0
    clear_stack(&t0);
    for (int i = 0; i < STACK_MAX_SIZE; i++)
    {
        CU_ASSERT_TRUE_FATAL(t0.data[i] == 0);
    }
    CU_ASSERT_TRUE_FATAL(t0.index == 0);
}

/*!
* \fn void assert_test_arraylist()
* \author GABETTE Cédric
* \version 0.1
* \date  15/10/2021
* \brief Unitary test with assert
* \remarks None
*/
void assert_test_arraylist()
{
    float a0 = 1.123;
    float b0 = 20.02;
    float c0 = 12.12;

    Array_list l0;

    //Initialize the list : verify if the first index is 0
    init_array_list(&l0);
    assert(l0.index == 0);
    //Put a value in a chosen position : verify if we find the value
    insert_at(&l0, 3, 1.123);
    assert(l0.data[3] == a0);
    //Remplace the last value equal to 0 with a new value : verify if we find the value
    add(&l0, 20.02);
    assert(l0.data[l0.index - 1] == b0);
    //Delete a value from a chosen position : verify if the value equals to 0
    float returning = remove_at(&l0, 3);
    assert(returning == a0);
    //Add et return the value of a chosen position : verify if the value match
    add(&l0, 12.12);
    get_at(&l0, 1);
    assert(l0.data[1] == c0);
    //Set all the values to 0 et set index to 0 : verify is index equals to 0
    clear_list(&l0);
    assert(l0.index == 0);
}

/*!
* \fn void cunit_test_arraylist()
* \author GABETTE Cédric
* \version 0.1
* \date  15/10/2021
* \brief Unitary test with CUnit
* \remarks None
*/
void cunit_test_arraylist()
{

    float a0 = 1.123;
    float b0 = 20.02;
    float c0 = 12.12;

    Array_list l0;

    //Initialize the list : verify if the first index is 0
    init_array_list(&l0);
    CU_ASSERT_TRUE_FATAL(l0.index == 0);
    //Put a value in a chosen position : verify if we find the value
    insert_at(&l0, 3, 1.123);
    CU_ASSERT_TRUE_FATAL(l0.data[3] == a0);
    //Remplace the last value equal to 0 with a new value : verify if we find the value
    add(&l0, 20.02);
    CU_ASSERT_TRUE_FATAL(l0.data[l0.index - 1] == b0);
    //Delete a value from a chosen position : verify the value of the removed value
    CU_ASSERT_EQUAL_FATAL(remove_at(&l0, 3), a0);
    //Add et return the value of a chosen position : verify if the value match
    add(&l0, 12.12);
    CU_ASSERT_EQUAL_FATAL(get_at(&l0, 1), c0);
    //Set all the values to 0 et set index to 0 : verify is index equals to 0
    clear_list(&l0);
    CU_ASSERT_TRUE_FATAL(l0.index == 0);
}

void assert_test_heap()
{
    Heap h;
    Heap m;
    init_heap(&h);
    assert(h.index == 0);
    assert(is_heap_empty(&h) == 1);
    push_heap(&h, 5.4f);
    assert(h.index == 1);
    assert(h.data[0] == 5.4f);
    push_heap(&h, 3.4f);
    push_heap(&h, 2.4f);
    push_heap(&h, 4.4f);
    assert(is_heap_empty(&h) == 0);
    assert(h.index == 4);
    assert(pop_heap(&h) == 2.4f);
    assert(h.index == 3);
    assert(replace(&h, 1.4f) == 3.4f);
    assert(peek_heap(&h) == 1.4f);
    merge(&m, &h);
}

/*!
* \fn void cunit_test_heap()
* \author Clément Couriol
* \version 0.1
* \date  17/10/2021
* \brief Unitary test with CUnit
* \remarks None
*/
void cunit_test_heap()
{
    Heap h;
    Heap m;
    init_heap(&h);
    CU_ASSERT_TRUE_FATAL(h.index == 0);
    CU_ASSERT_EQUAL_FATAL(is_heap_empty(&h), 1);
    push_heap(&h, 5.4f);
    CU_ASSERT_TRUE_FATAL(h.index == 1);
    CU_ASSERT_TRUE_FATAL(h.data[0] == 5.4f);
    push_heap(&h, 3.4f);
    push_heap(&h, 2.4f);
    push_heap(&h, 4.4f);
    CU_ASSERT_EQUAL_FATAL(is_heap_empty(&h), 0);
    CU_ASSERT_TRUE_FATAL(h.index == 4);
    CU_ASSERT_EQUAL_FATAL(pop_heap(&h), 2.4f);
    CU_ASSERT_TRUE_FATAL(h.index == 3);
    CU_ASSERT_EQUAL_FATAL(replace(&h, 1.4f), 3.4f);
    CU_ASSERT_EQUAL_FATAL(peek_heap(&h), 1.4f);
    merge(&m, &h);
}