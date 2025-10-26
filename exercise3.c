/*
 * Exercise 3: Queue Implementation using Singly-Linked Lists
 * Assignment 8 - IPFCE 2025
 * 
 * Implement a queue using singly-linked lists.
 * The queue should maintain FIFO (First-In, First-Out) order.
 */

#include "exercise3.h"

/* 
 * Initialize an empty queue
 * q: pointer to the queue structure
 * 
 * Post-condition: queue is empty with front and rear set to NULL
 */
void initialize(queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
    /* TODO: Initialize the queue */
}
/* 
 * Insert item x at the back of queue q
 * q: pointer to the queue structure
 * x: item to be inserted
 * 
 * Pre-condition: queue is not full
 * Post-condition: x is added to the rear of the queue
 */
void enqueue(queue *q, int x) {
    /* TODO: Implement enqueue */
    node *n = (node *)malloc(sizeof(node));
    if(!n) {
        fprintf(stderr, "enqueue er ude af memory\n");
        exit(EXIT_FAILURE);
     }
    n->data = x;
    n->next = NULL;

    if(q->front == NULL) {
       q->front = q->rear = n;
    } else {
       q->rear->next = n;
         q->rear = n;

    }
    q->count++;

}
/* 
 * Return (and remove) the front item from queue q
 * q: pointer to the queue structure
 * 
 * Pre-condition: queue must not be empty
 * Post-condition: front item is removed and returned
 */
int dequeue(queue *q) {
    if (q->front == NULL) {
        fprintf(stderr, "dequeue fra en tom queue\n");
        exit(EXIT_FAILURE);
    }   
    node *first = q->front;
    int value = first->data;

    q->front = first->next;
    if (q->front == NULL) {
        q->rear = NULL; // Queue is now empty
    }
    free(first);
    q->count--;
    return value;  
}

/* 
 * Check if the queue is empty
 * q: pointer to the queue structure
 * Returns: true if queue is empty, false otherwise
 */
bool empty(const queue *q) {
    return (q->front == NULL); // Queue is empty if front is NULL
}
/* 
 * Check if the queue is full
 * q: pointer to the queue structure
 * Returns: true if queue is full, false otherwise
 */
bool full(const queue *q) {
    (void)q; // Unused parameter
    return false;
}

/* Helper function to print the queue */
void print_queue(const queue *q) {
    printf("Queue (front to rear): ");
    node *current = q->front;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" <- ");
        }
        current = current->next;
    }
    printf("\n");
}

