#include "queue.h"
#include <memory.h>
#include <stdlib.h>
Queue* create(int elementSize, int length){
    Queue* queue;
    queue = (Queue*)malloc(sizeof(Queue));
    queue->base = calloc(length, elementSize);
    queue->elementSize = elementSize;
    queue->front = 0;
    queue->rear = 0;
    queue->length = length;
    return queue;
}

int enqueue(Queue* queue, void* element){
	void *copyTo;
    if(queueIsFull(queue))
        return 0;
    copyTo = queue->base+(queue->rear++)*queue->elementSize;
    memmove(copyTo , element, queue->elementSize);
    return 1;
}
int queueIsFull(Queue* queue){
	if(queue->length == queue->rear)
		return 1;
	return 0;
}

void* dequeue(Queue *queue){
	void* deletedElement=malloc(queue->elementSize);
	void *copyFrom, *copyTo;
	size_t noOfBytesToCopy;
	if(queueIsEmpty(queue))
		return NULL;
	memcpy(deletedElement, queue->base, queue->elementSize);
	copyFrom = queue->base+queue->elementSize;
	copyTo = queue->base;
	noOfBytesToCopy = (queue->length-1)*queue->elementSize;
	memmove(copyTo, copyFrom, noOfBytesToCopy);
	return deletedElement;
}
int queueIsEmpty(Queue* queue){
	if(queue->rear == queue->front)
		return 1;
	return 0;
}

