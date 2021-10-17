/*!
* \file stack.c
* \author GABETTE Cédric <sirdricks@outlook.com>
* \version 0.1
* \date 13/10/2021
* \brief Contains all the functions for a stack
* \remarks None
* 
* 
* 
*/

/*! Importation of librairies*/
#include "../include/stack.h"
/*!
* \fn void push(Stack *s, float value)
* \author GABETTE Cédric <sirdricks@outlook.com>
* \version 0.1
* \date  13/10/2021
* \brief  Put a value on the top of the stack
* \remarks Can put a value out of stack 
* \param s 
* \param value 
*/
//TODO: Prevent pushing above the STACK_MAX_SIZE limit
void push_stack(Stack *s, float value)
{
    s->data[s->index] = value;
    s->index++;
}

/*!
* \fn void init_stack(Stack *s)
* \author GABETTE Cédric <sirdricks@outlook.com>
* \version 0.1
* \date  13/10/2021
* \brief Initialize the stack with values set to 0
* \remarks None
* \param s 
*/
//TODO: Setting the values to NULL and not to 0, for preventing confusion with real value 0
void init_stack(Stack *s)
{
    for (int i = 0; i < STACK_MAX_SIZE; i++)
    {
        s->data[i] = 0;
    }
    s->index = 0;
}

/*!
* \fn float pop(Stack *s)
* \author GABETTE Cédric <sirdricks@outlook.com>
* \version 0.1
* \date  13/10/2021
* \brief Take out the the value on the top of the stack
* \remarks When user uses pop in an empty stack, the function cannot return a "null value", return -1 instead.
* \param s 
* \return 
*/
//TODO: Prevent poping a empty stack
float pop_stack(Stack *s)
{
    float topop = 0;
    s->index--;
    if (s->index < 0)
    {
        s->index = 0;
        return -1;
    }
    topop = (s->data[s->index]);
    s->data[s->index] = 0;

    return topop;
}

/*!
* \fn bool is_stack_empty(Stack *s)
* \author GABETTE Cédric <sirdricks@outlook.com>
* \version 0.1
* \date  13/10/2021
* \brief Verify if the stack is empty
* \remarks None
* \param s 
* \return 
*/
bool is_stack_empty(Stack *s)
{
    if (s->index == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*!
* \fn float peek_stack(Stack *s) 
* \author GABETTE Cédric <sirdricks@outlook.com>
* \version 0.1
* \date  13/10/2021
* \brief Copy the value on the top of the stack
* \remarks None
* \param s 
* \return 
*/
float peek_stack(Stack *s)
{
    s->index--;
    float copy;
    copy = (s->data[s->index]);
    s->index++;
    return copy;
}

/*!
* \fn void dup(Stack *s) 
* \author GABETTE Cédric <sirdricks@outlook.com>
* \version 0.1
* \date  13/10/2021
* \brief Duplicate the value on the top of the stack and add it above the original
* \remarks None
* \param s 
*/
void dup(Stack *s)
{
    s->index--;
    float duplicate = s->data[s->index];
    s->index++;
    s->data[s->index] = duplicate;
    s->index++;
}

/*!
* \fn void swap(Stack *s) 
* \author GABETTE Cédric <sirdricks@outlook.com>
* \version 0.1
* \date  13/10/2021
* \brief Swap the first and the seconde value on the top of the stack
* \remarks None
* \param s 
*/
void swap(Stack *s)
{
    s->index--;
    float swap = s->data[s->index - 1];
    s->data[s->index - 1] = s->data[s->index];
    s->data[s->index] = swap;
    s->index++;
}

/*!
* \fn void clear_stack(Stack *s) 
* \author GABETTE Cédric <sirdricks@outlook.com>
* \version 0.1
* \date  13/10/2021
* \brief Clear the whole stack by setting the values to 0
* \remarks None
* \param s 
*/
//TODO: Setting the values to NULL and not to 0, for preventing confusion with real value 0
void clear_stack(Stack *s)
{
    for (int i = 0; i < STACK_MAX_SIZE; i++)
    {
        s->data[i] = 0;
    }
    s->index = 0;
}