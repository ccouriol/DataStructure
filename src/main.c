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

#include "../include/stack.h"

/*!
* \fn float test(int a)
* \author Name <email@email.com>
* \version 0.1
* \date  13/10/2021
* \brief 
* \remarks None
* \param a 
* \return 
*/
float test(int a)
{
    errno = a;
    assert(a == 5);
    int errnum = errno;
    fprintf(stderr, "Value of errno: %d\n", errnum);
    perror("Error printed by perror");
    fprintf(stderr, "Error opening file: %s\n", strerror(errnum));
}

/*!
* \fn int main(int argc, char **argv)
* \author Clément Couriol
* \version 0.1
* \date 13/10/2021
* \brief Main function of the program
* \remarks None
* \param argc number of arguments given as inputs
* \param argv value of arguments given as inputs
* \return 0 if all went good
*/
int main(int argc, char **argv)
{

    return (EXIT_SUCCESS);
}

void test_stack()
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