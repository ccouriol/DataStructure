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

#include "../include/array_list.h"

void test_arraylist();

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

    test_arraylist();

    return (EXIT_SUCCESS);
}

void test_arraylist()
{
    float a0 = 1.123;
    float b0 = 20.02;
    float c0 = 12.12;

    Array_list l0;
    long l = &l0;

    //Initialize the list : verify if the first index is 0
    init_array_list(l);
    assert(l0.index == 0);
    //Put a value in a chosen position : verify if we find the value
    insert_at(l, 3, 1.123);
    assert(l0.data[3] == a0);
    //Remplace the last value equal to 0 with a new value : verify if we find the value
    add(l, 20.02);
    assert(l0.data[l0.index - 1] == b0);
    //Delete a value from a chosen position : verify if the value equals to 0
    float returning = remove_at(l, 3);
    assert(returning == a0);
    //Add et return the value of a chosen position : verify if the value match
    add(l, 12.12);
    get_at(l, 1);
    assert(l0.data[1] == c0);
    //Set all the values to 0 et set index to 0 : verify is index equals to 0
    clear_list(l);
    assert(l0.index == 0);
}