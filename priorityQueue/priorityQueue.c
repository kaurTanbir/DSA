#include "./include/circular_queue.h"
#include "priorityQueue.h"
#include <memory.h>
#include <stdlib.h>

PriorityQueue* createPQ(int elementSize,int length){
    Queue* queue;
    PriorityQueue* pqueue;
    queue = create(elementSize, length);
    pqueue->elements = queue;
    return pqueue; 
}


int Penqueue(PriorityQueue* Pqueue, data_specification* element){
    int j;
    Queue *queue = (Queue*)Pqueue->elements;
    data_specification* elementToCompare;
    data_specification* res;

    if(queueIsFull(queue))
        return 0;
    if(queue->rear >= queue->length)
    	queue->rear = 0;
    if(queue->front == -1 && queue->rear == -1){
    	queue->front++;
    	queue->rear++;
        memmove(queue->base, element, queue->elementSize);
        return 1;
    }
    queue->rear++;
    for (j = queue->rear-1; j >= queue->front; j--) {
        elementToCompare = queue->base + j * queue->elementSize;
        if (element->priority >= elementToCompare->priority) 
            break; 
        memmove(elementToCompare + queue->elementSize, 
        elementToCompare, queue->elementSize);    
    } 
    memmove(queue->base+((j+1)*queue->elementSize), element, queue->elementSize);
    return 1;    
}
void* dequeuePQ(PriorityQueue* Pqueue){
    Queue *queue = (Queue*)Pqueue->elements;
    return dequeue(queue);
}
 