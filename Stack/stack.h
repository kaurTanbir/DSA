#include "./include/custom_dataType.h"

Stack* create(int length,int elementSize);
int push(Stack* stack,void* element);
void* pop(Stack* stack);
void* peek(Stack stack);
