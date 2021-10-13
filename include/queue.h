/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   queue.h
 * Author: aurelio
 *
 */

#include <stdbool.h>

#ifndef QUEUE_H
#define QUEUE_H


#define QUEUE_MAX_SIZE 100

typedef struct {
    float data[QUEUE_MAX_SIZE];
    int index;
} Queue;


#endif /* QUEUE_H */

void init_queue(Queue *s);
void enqueue(Queue *q, float value);
float dequeue(Queue *q);

bool is_queue_empty(Queue *q);
float front(Queue *q); //aka peek
void clear(Queue *q);

