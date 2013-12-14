#include <stdbool.h>
#include "./include/circular_queue.h"


typedef int (*compare)(void* first, void* second);

int Penqueue(Queue* queue, void* element,compare comp);
