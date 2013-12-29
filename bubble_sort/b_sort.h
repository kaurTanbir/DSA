#include "../custom_dataType.h"
typedef int (*Compare)(void* element1, void* element2);

void sort(void* elements, int numberOfElements, int elementSize,Compare compareFunc); 