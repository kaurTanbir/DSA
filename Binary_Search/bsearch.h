#include <memory.h>
#include "./include/custom_dataType.h"

void* binarySearch (void* key,void* base,
               size_t totalElements, size_t elementSize,
               CompareFunc* compare);