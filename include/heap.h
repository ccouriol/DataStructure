/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   heap.h
 * Author: aurelio
 *
 */

#include <stdbool.h>

#ifndef HEAP_H
#define HEAP_H


#define HEAP_MAX_SIZE 100

typedef struct {
    float data[HEAP_MAX_SIZE];
    int index;
} Heap;


#endif /* HEAP_H */

void init_heap(Heap *h);
bool is_heap_empty(Heap *h);
float pop(Heap *h); //pop the root value
void push(Heap *h, float value);
float replace(Heap *h, float value); // pop root and push a new key.
float peek(Heap *h); // return root value but dont remove it

//En option
void heapify(Heap *s, float array[], size_t array_size); //create Heap from array
void merge(Heap *dest, Heap *src); //merge src into dest


