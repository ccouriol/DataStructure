/*!
* \file array_list.c
* \author GABETTE Cédric <sirdricks@outlook.com>
* \version 0.1
* \date 14/10/2021
* \brief Contains all the functions for an array list
* \remarks None
* 
* 
* 
*/

/*! Importation of librairies*/
#include "../include/array_list.h"

/*!
* \fn void init_array_list(Array_list *l)
* \author GABETTE Cédric <sirdricks@outlook.com>
* \version 0.1
* \date  14/10/2021
* \brief Initialize the list with values equals to 0
* \remarks None
* \param l 
*/
//TODO: Remplace the value 0 by a null value, to avoid confusion with a real value "0"
void init_array_list(Array_list *l)
{
    for (int i = 0; i < ARRAY_LIST_MAX_SIZE; i++)
    {
        l->data[i] = 0;
    }
    l->index = 0;
}

/*!
* \fn void insert_at(Array_list *l, int position, float value)
* \author GABETTE Cédric <sirdricks@outlook.com>
* \version 0.1
* \date  14/10/2021
* \brief Put a value in a choosen position 
* \remarks User can choose a position above the limit, resulting to put a value out of the list
* \param l 
* \param position 
* \param value 
*/
//TODO: Position must be inferior to ARRAY_LIST_MAX_SIZE
void insert_at(Array_list *l, int position, float value)

    {
        l->data[position] = value;
    }

/*!
* \fn void add(Array_list *l, float value)
* \author GABETTE Cédric <sirdricks@outlook.com>
* \version 0.1
* \date  14/10/2021
* \brief Put a value from the begining of the list, act like a stack
* \remarks Can add a value out of the list if we reach the max limit
* \param l 
* \param value 
*/
//TODO: Prevent adding a value above ARRAY_LIST_MAX_SIZE delimitation
void add(Array_list *l, float value)
{
    l->data[l->index] = value;
    l->index++;
}

/*!
* \fn float remove_at(Array_list *l, int position)
* \author GABETTE Cédric <sirdricks@outlook.com>
* \version 0.1
* \date  14/10/2021
* \brief Delete the value from a choosen position
* \remarks None
* \param l 
* \param position 
* \return 
*/
//TODO: Position must be inferior to ARRAY_LIST_MAX_SIZE
float remove_at(Array_list *l, int position)
{
    float toReturn = l->data[position];
    l->data[position] = 0;
    return toReturn;
}

/*!
* \fn float get_at(Array_list *l,int position)
* \author GABETTE Cédric <sirdricks@outlook.com>
* \version 0.1
* \date  14/10/2021
* \brief return the value of a choosen position
* \remarks None
* \param l 
* \param position 
* \return 
*/
//TODO: Position must be inferior to ARRAY_LIST_MAX_SIZE
float get_at(Array_list *l, int position)
{
    return (l->data[position]);
}

/*!
* \fn void clear_list(Array_list *l)
* \author GABETTE Cédric <sirdricks@outlook.com>
* \version 0.1
* \date  14/10/2021
* \brief Clear the whole list by setting the values to 0
* \remarks None
* \param l 
*/
//TODO: Remplace the value 0 by a null value, to avoid confusion with a real value "0"
void clear_list(Array_list *l)
{
    for (int i = 0; i < ARRAY_LIST_MAX_SIZE; i++)
    {
        l->data[i] = 0;
    }
    l->index = 0;
}
