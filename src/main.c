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
