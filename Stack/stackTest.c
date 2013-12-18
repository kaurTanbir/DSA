#include "testUtils.h"
#include "stack.h"
#include <memory.h>
#include <stdlib.h>
typedef char String[256];

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
Stack* stack;
void tearDown(){

}
//------------------------------push-------------------------------------

void test_adds_the_given_integer_to_the_stack(){
    int num = 10;
    int* res;
    stack = create(1);
    push(stack, &num);
    res = peek(*stack);
    ASSERT(10 == *res);
}

void test_adds_the_given_doubles_to_the_stack(){
	double first = 10.0;
    double* res;
    stack = create(2);
    push(stack, &first);
    res = peek(*stack);
    ASSERT(10.0 == *res);
}

void test_adds_the_given_characters_to_the_stack(){
    char first = 'a',
    	second = 'b';
    char *res;
    stack = create(2);
    push(stack, &first);
    push(stack, &second);
    res = peek(*stack);
    ASSERT('b' == *res);
}

void test_adds_the_given_Strings_at_the_top_of_the_stack(){
    String name1 = "abc";
    String* res;
    stack = create(1);
    push(stack, &name1);
    res = peek(*stack);
    ASSERT(0 == strcmp(name1,*res));


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
void test_adds_the_given_integer_to_the_stack_and_returns_1(){
    int num = 10;
    int res;
    stack = create(1);
    res = push(stack, &num);
    ASSERT(1 == res);
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
    result = peek(*stack);
    ASSERT(10 == *result);
};

void test_gives_the_top_most_double(){
    double* result;
    double first = 10.0,
			second =20.0;
    stack = create(2);
    push(stack, &first);
    push(stack, &second);
    result = peek(*stack);
    ASSERT(20.0 == *result);
};

void test_gives_the_top_most_character(){
	char* result;
	char first = 'a',
	second = 'b';
	stack = create(3);
	push(stack, &first);
	push(stack, &second);
	result = peek(*stack);
	ASSERT('b' == *result);
};

void test_gives_the_top_most_element_from_the_stack_Strings(){
    char* result;
    String name1 = "abc",
    	 name2 = "def";
    stack = create(2);
    push(stack, &name1);
    push(stack, &name2);
    result = peek(*stack);
    ASSERT(0 == strcmp("def", result));
};


void test_returns_null_when_trying_access_the_element_if_top_is_zero(){
    void* result;
    stack = create(3);
    result = peek(*stack);
    ASSERT(NULL == result);
}

