#include <stdbool.h>
#include "./include/custom_dataType.h"

Queue* create(int elementSize,int length);
int enqueue(Queue* queue, void* element);
void* dequeue(Queue* queue);
