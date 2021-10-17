/*!
* \file heap.c
* \author Clément Couriol
* \version 0.1
* \date 17/10/2021
* \brief 
* \remarks None
* 
* 
* 
*/

/*! Importation of librairies*/
#include "../include/heap.h"

/*!
* \fn void init_heap(Heap *h)
* \author Clément Couriol
* \version 0.1
* \date  17/10/2021
* \brief init the heap index to 0
* \remarks None
* \param h 
*/
void init_heap(Heap *h)
{
  h->index = 0;
}

/*!
* \fn bool is_heap_empty(Heap *h)
* \author Clément Couriol
* \version 0.1
* \date  17/10/2021
* \brief returns 1 or 0 if queue is empty or not
* \remarks None
* \param h 
* \return 
*/
bool is_heap_empty(Heap *h)
{
  return h->index == 0;
}

/*!
* \fn float pop_heap(Heap *h) 
* \author Clément Couriol
* \version 0.1
* \date  17/10/2021
* \brief remove the first value of heap & returns it
* \remarks None
* \param h 
* \return 
*/
float pop_heap(Heap *h)
{
  float firstValue = h->data[0];
  for (int i = 0; i < h->index; i++)
    h->data[i] = h->data[i + 1];
  h->index--;
  heapsort(h);
  return firstValue;
}

/*!
* \fn void push_heap(Heap *h, float value)
* \author Clément Couriol
* \version 0.1
* \date  17/10/2021
* \brief add a value to heap
* \remarks Doesn't check if the HEAP_MAX_SIZE value is exceeded
* \param h 
* \param value 
*/
void push_heap(Heap *h, float value)
{
  h->data[h->index] = value;
  h->index++;
  heapsort(h);
}

/*!
* \fn float replace(Heap *h, float value) 
* \author Clément Couriol
* \version 0.1
* \date  17/10/2021
* \brief pop root and push a new key
* \remarks None
* \param h 
* \param value 
* \return 
*/
float replace(Heap *h, float value)
{
  float root = h->data[0];
  h->data[0] = value;
  heapsort(h);
  return root;
}

/*!
* \fn float peek_heap(Heap *h) 
* \author Clément Couriol
* \version 0.1
* \date  17/10/2021
* \brief return root value but dont remove it
* \remarks None
* \param h 
* \return 
*/
float peek_heap(Heap *h)
{
  return h->data[0];
}

/*!
* \fn void heapify(Heap *h, float array[], size_t array_size) 
* \author Clément Couriol
* \version 0.1
* \date  17/10/2021
* \brief create Heap from array
* \remarks None
* \param h 
* \param array 
* \param array_size 
*/
void heapify(Heap *h, float array[], size_t array_size)
{
  long int largest = array_size;
  int leftChild = 2 * array_size + 1;
  int rightChild = 2 * array_size + 2;

  if (leftChild < array[0] && h->data[leftChild] > h->data[largest])
    largest = leftChild;

  if (rightChild < array[0] && h->data[rightChild] > h->data[largest])
    largest = rightChild;

  if (largest != array_size)
  {
    float tmp = h->data[array_size];
    h->data[array_size] = h->data[largest];
    h->data[largest] = tmp;
    heapify(h, &array[0], largest);
  }
}

/*!
* \fn void heapsort(Heap *h)
* \author Clément Couriol
* \version 0.1
* \date  17/10/2021
* \brief 
* \remarks None
* \param h 
*/
void heapsort(Heap *h)
{
  for (int i = h->index / 2 - 1; i >= 0; i--)
  {
    float arr[] = {h->index};
    heapify(h, &arr[0], i);
  }

  for (int i = h->index - 1; i > 0; i--)
  {
    float arr[] = {i};
    float tmp = h->data[0];
    h->data[0] = h->data[i];
    h->data[i] = tmp;
    heapify(h, &arr[0], 0);
  }
}

/*!
* \fn void merge(Heap *dest, Heap *src) 
* \author Clément Couriol
* \version 0.1
* \date  17/10/2021
* \brief merge src into dest
* \remarks None
* \param dest 
* \param src 
*/
void merge(Heap *dest, Heap *src)
{
  for (size_t i = 0; i < src->index; i++)
    dest->data[i] = src->data[i];
  heapsort(dest);
}
