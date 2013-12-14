#include "testUtils.h"
#include "stack.h"
#include <memory.h>
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
Stack* stack;
int areEqual(Stack a, Stack b){
    int result = a.length == b.length && a.top == b.top;
    if(!result) return result;
    return 0 == memcmp(a.base,b.base,a.length*sizeof(void*));
}

//------------------------------------------------Create---------------------------

void test_creates_a_stack_for_with_given_length (){
    void* Nulls[3] = {NULL,NULL,NULL};
    Stack expected = {Nulls,0,3};
    stack = create(3);
    ASSERT(areEqual(expected, *stack));
};
//------------------------------push-------------------------------------

void test_adds_the_given_integer_to_the_stack(){
    int num = 10;
    stack = create(1);
    push(stack, &num);
    ASSERT(10 == **(int**)stack->base);
    ASSERT(1 == stack->top && 1 == stack->length);
}

void test_adds_the_given_doubles_to_the_stack(){
	double first = 10.0,
			second =20.0;
    stack = create(2);
    push(stack, &first);
    push(stack, &second);
    ASSERT(10.0 == **(double**)stack->base);
    ASSERT(2 == stack->top && 2 == stack->length);
}

void test_adds_the_given_characters_to_the_stack(){
    char first = 'a',
    	second = 'b';
    stack = create(3);
    push(stack, &first);
    push(stack, &second);
    ASSERT(2 == stack->top && 3 == stack->length);
}

void test_adds_the_given_Strings_at_the_top_of_the_stack(){
    String name1 = "abc",
    		name2 = "def";
    stack = create(2);
    push(stack, &name1);
    push(stack, &name2);
}

void test_doubles_the_length_of_stack_if_stack_is_full(){
    int num1 = 10,
    	num2 = 20,
    	result;
    stack = create(2);
    push(stack, &num1);
    push(stack, &num2);
    ASSERT(2 == stack->length);
    result = push(stack, &num1);
    ASSERT(1 == result);
    ASSERT(4 == stack->length);
    ASSERT(3 == stack->top);
}

//--------------------------------pop---------------------------------------

void test_removes_the_topmost_integer_from_the_stack(){
    int num1 = 10,
    	num2 = 20;
    int* result;
    stack = create(2);
    push(stack, &num1);
    push(stack, &num2);
    result = pop(stack);
    ASSERT(20 == *result);
    ASSERT(1==stack->top);
};

void test_removes_the_top_most_double_element_from_the_stack(){
    double* result;
    double first = 10.0,
			second =20.0;
    stack = create(2);
    push(stack, &first);
    push(stack, &second);
    result = pop(stack);
    ASSERT(20.0 == *result);
    ASSERT(1 == stack->top);
};

void test_removes_the_top_most_character_from_the_stack(){
    char* result;
    char first = 'a',
    	second = 'b';
    stack = create(3);
    push(stack, &first);
    push(stack, &second);
    result = pop(stack);
    ASSERT('b' == *result);
    ASSERT(1 == stack->top);
};


void test_returns_null_when_deleted_from_empty_stack(){
    void* result;
    stack = create(5);
    result = pop(stack);
    ASSERT(NULL == result);
}

//--------------------------------peek-------------------------------------

void test_gives_the_top_most_integer(){
    int* result;
    int num = 10;
    stack = create(1);
    push(stack, &num);
    result = peek(stack);
    ASSERT(10 == *result);
    ASSERT(1 == stack->top);
};

void test_gives_the_top_most_double(){
    double* result;
    double first = 10.0,
			second =20.0;
    stack = create(2);
    push(stack, &first);
    push(stack, &second);
    result = peek(stack);
    ASSERT(20.0 == *result);
    ASSERT(2 == stack->top);
};

void test_gives_the_top_most_character(){
	char* result;
	char first = 'a',
	second = 'b';
	stack = create(3);
	push(stack, &first);
	push(stack, &second);
	result = peek(stack);
	ASSERT('b' == *result);
	ASSERT(2 == stack->top);
};

void test_gives_the_top_most_element_from_the_stack_Strings(){
    char* result;
    String name1 = "abc",
    	 name2 = "def";
    stack = create(2);
    push(stack, &name1);
    push(stack, &name2);
    result = peek(stack);
    ASSERT(0 == strcmp("def", result));
    ASSERT(2 == stack->top);
};


void test_returns_null_when_trying_access_the_element_if_top_is_zero(){
    void* result;
    stack = create(3);
    result = peek(stack);
    ASSERT(NULL == result);
}

//-------------------------------------isEmpty---------------------------

void test_tells_the_stack_is_empty(){
    int result;
    stack = create(2);
    result = isEmpty(stack);
    ASSERT(1==result);
}

void test_tells_the_stack_is_not_empty(){
    int result;
    stack = create(3);
    stack->top = 1;
    result = isEmpty(stack);
    ASSERT(0==result);
}

//--------------------------isFull--------------------------------------

void test_tells_the_stack_is_full_integers(){
    int num = 10,result;
    stack = create(1);
    push(stack, &num);
    result = isFull(stack);
    ASSERT(1==result);
}

void test_tells_the_stack_is_not_full(){
    int result;
    stack = create(2);
    result = isFull(stack);
    ASSERT(0==result);
}