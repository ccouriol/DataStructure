/*!
* \file queue.c
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
#include "../include/queue.h"

/*!
* \fn void init_queue(Queue *q)
* \author Clément Couriol
* \version 0.1
* \date  13/10/2021
* \brief init the queue index to 0
* \remarks None
* \param q
*/
void init_queue(Queue *q)
{
  q->index = 0;
}

/*!
* \fn void enqueue(Queue *q, float value)
* \author Clément Couriol
* \version 0.1
* \date  13/10/2021
* \brief add a value to a queue
* \remarks Doesn't check if the QUEUE_MAX_SIZE value is exceeded
* \param q 
* \param value 
*/
void enqueue(Queue *q, float value)
{
  q->data[q->index] = value;
  q->index++;
}

/*!
* \fn float dequeue(Queue *q)
* \author Clément Couriol
* \version 0.1
* \date  13/10/2021
* \brief remove the first value of a queue & returns it
* \remarks Doesn't check if the queue is empty
* \param q 
* \return 
*/
float dequeue(Queue *q)
{
  float firstValue = q->data[0];
  for (int i = 0; i < q->index; i++)
    q->data[i] = q->data[i + 1];
  q->index--;
  return firstValue;
}

/*!
* \fn bool is_queue_empty(Queue *q)
* \author Clément Couriol
* \version 0.1
* \date  13/10/2021
* \brief returns 1 or 0 if queue is empty or not
* \remarks None
* \param q 
* \return 
*/
bool is_queue_empty(Queue *q)
{
  return q->index == 0;
}

/*!
* \fn float front_queue(Queue *q)
* \author Clément Couriol
* \version 0.1
* \date  13/10/2021
* \brief Return the first value of the queue
* \remarks None
* \param q 
* \return 
*/
float front_queue(Queue *q)
{
  return q->data[0];
}

/*!
* \fn void clear_queue(Queue *q)
* \author Clément Couriol
* \version 0.1
* \date  13/10/2021
* \brief Sets all the current value to 0 and then set the index to 0
* \remarks None
* \param q 
*/
void clear_queue(Queue *q)
{
  for (int i = 0; i < q->index; i++)
    q->data[i] = 0;
  q->index = 0;
}