#include "./include/custom_dataType.h"

typedef struct {
	void* elements;
} PriorityQueue;

PriorityQueue* createPQ(int elementSize,int length);
int Penqueue(PriorityQueue* queue, data_specification* element);
void* dequeuePQ(PriorityQueue* queue);