#include "stack.h"
#include <stdlib.h>
#include <memory.h>

Stack *create(int length, int elementSize){
    Stack* stack;
    stack = (Stack*)calloc(sizeof(Stack), 1);
    stack->base = calloc(elementSize, length);
    stack->length = length;
    stack->top = 0;
    stack->elementSize = elementSize;
    return stack;
}

int isFull(Stack stack){
    if(stack.top==stack.length)
        return 1;
    return 0;
}


int push(Stack* stack,void* element){
	void* newSize;
        if(isFull(*stack)){
            newSize = realloc(stack->base, stack->length * 2 * stack->elementSize);
            if(!newSize)
                return 0;
            stack->base = newSize;
            stack->length *= 2;
        }
	memcpy((stack->base + (stack->top * stack->elementSize)), element, stack->elementSize);
	return 1;
}
int isEmpty(Stack stack){
    if(stack.top)
        return 0;
    return 1;
}
void* pop(Stack* stack){
    if(isEmpty(*stack))
        return NULL;
    return stack->base + ((--stack->top)* stack->elementSize);
};
void* peek(Stack stack){
    return stack.base + ((stack.top-1)* stack.elementSize);
}


