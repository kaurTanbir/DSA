#include <stdbool.h>
#include "./include/circular_queue.h"
typedef struct {
    void* data;
    int priority;
}data_specification;

typedef int (*compare)(void* first, void* second);

int Penqueue(Queue* queue, data_specification* element);
