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
#include "../include/queue.h"

/*!
* \fn float test(int a)
* \author Clément couriol
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

void test_queue(int a)
{
    Queue qu;
    init_queue(&qu);
    enqueue(&qu, 1.4);
    enqueue(&qu, 2.4);
    enqueue(&qu, 3.4);
    for (int i = 0; i < qu.index; i++)
        printf("%f\n", qu.data[i]);
    printf("%i\n", qu.index);

    float dequ = dequeue(&qu);
    puts("qu dequeue");

    for (int i = 0; i < qu.index; i++)
        printf("%f\n", qu.data[i]);

    printf("dequ : %f\n", dequ);
    printf("empty %i\n", is_queue_empty(&qu));
    dequ = front(&qu);
    printf("dequ : %f\n", dequ);
    for (int i = 0; i < qu.index; i++)
        printf("%f\n", qu.data[i]);

    clear_queue(&qu);
    puts("clear happened");
    printf("empty %i\n", is_queue_empty(&qu));
    enqueue(&qu, 6.4);
    enqueue(&qu, 7.4);
    enqueue(&qu, 8.4);
    for (int i = 0; i < qu.index; i++)
        printf("%f\n", qu.data[i]);
}