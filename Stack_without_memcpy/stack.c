#include "stack.h"
#include <stdlib.h>


Stack* create(int length){
    Stack* stack;
    stack = (Stack*)calloc(sizeof(Stack), 1);
    stack->base = calloc(sizeof(void*), length);
    stack->length = length;
    stack->top = 0;
    return stack;
}

int isFull(Stack stack){
    return stack.top == stack.length;
}

int push(Stack* stack,void* element){
    void* temp;
    if(isFull(*stack)){
        temp = realloc(stack->base, stack->length * 2 * sizeof(void*));
        stack->base = temp;
        stack->length *= 2;
    }
    *(stack->base + (stack->top++ )) = element;
    return 1;
}

int isEmpty(Stack stack){
    return stack.top == 0;
}

void* pop(Stack* stack){
    if(isEmpty(*stack)) 
    	return NULL;
    return *(stack->base + --stack->top );
};

void* peek(Stack stack){
    if(isEmpty(stack))
    	return NULL;
    return *(stack.base + (stack.top-1));
}
