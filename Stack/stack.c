#include "stack.h"
#include <stdlib.h>
#include <memory.h>
void* getElement(Stack *stack,int top){
	return(stack->base + (top * stack->elementSize));
}
Stack *create(int length, int elementSize){
    Stack* stack;
    stack = calloc(sizeof(Stack), 1);
    stack->base = calloc(elementSize, length);
    stack->length = length;
    stack->top = 0;
    stack->elementSize = elementSize;
    return stack;
}
bool push(Stack* stack,void* element){
	if(isFull(stack))
		return false;
	memcpy(getElement(stack,(stack->top++)), element, stack->elementSize);
	return true;
}
void* pop(Stack* stack){
    if(isEmpty(stack))
        return NULL;
    return getElement(stack,(--stack->top));
};
void* peek(Stack* stack){
        return getElement(stack,(stack->top-1));
}

int isEmpty(Stack* stack){
        if(stack->top)
                return 0;
        return 1;
}

int isFull(Stack* stack){
        if(stack->top==stack->length)
                return 1;
        return 0;
}

