#include "testUtils.h"
#include "stack.h"
#include <string.h>

//--------------------------create----------------------------------
void test_create_stack(){
    Stack* stack;
    stack = createStack();
    ASSERT(stack->head == NULL);         
    ASSERT(stack->length == 0);         
}
//---------------------------push------------------------------------

void test_push_integer_element_at_start_of_stack(){
    Stack* stack;
    int element = 10,
        res;
    stack = createStack();
    res = push(stack , &element);
    ASSERT(1 == res);         
}
void test_push_double_element_at_start_of_stack(){
    Stack* stack;
    double element = 10.0;int res;
    stack = createStack();
    res = push(stack , &element);
    ASSERT(1 == res);         
}
void test_push_character_element_at_start_of_stack(){
    Stack* stack;
    char element = 'a';int res;
    stack = createStack();
    res = push(stack , &element);
    ASSERT(1 == res);         
}
void test_push_string_element_at_start_of_stack(){
    Stack* stack;
    String element;
    int res;
    strcpy(element , "abc");
    stack = createStack();
    res = push(stack , &element);
    ASSERT(1 == res);         
}

//-----------------------------pop----------------------------------------- 


void test_pop_int_element_at_top_of_stack(){
    Stack* stack;
    int data;
    int element1 = 10,
    	element2 = 20;
    stack = createStack();
    push(stack , &element1);
    push(stack , &element2);
    data =(int)pop(stack);         
    ASSERT(*(int*)data == 20);         
}
void test_pop_double_element_at_top_of_stack(){
    Stack* stack;
    int data;
    double element1 = 10.0,element2 = 20.0;
    stack = createStack();
    push(stack , &element1);
    push(stack , &element2);
    data =(int)pop(stack);         
    ASSERT(*(double*)data == 20.0);         
}

//------------------------top------------------------------------
void test_gives_the_topmost_int_element_at_top_of_stack(){
    Stack* stack;
    int data;
    int element1 = 10,
    	element2 = 20;
    stack = createStack();
    push(stack , &element1);
    push(stack , &element2);
    data =(int)top(*stack);         
    ASSERT(*(int*)data == 20);         
}