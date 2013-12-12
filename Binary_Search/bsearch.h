#include <memory.h>
typedef int CompareFunc (void* ,void*);
void* binarySearch (void* key,void* base,
               size_t totalElements, size_t elementSize,
               CompareFunc* compare);