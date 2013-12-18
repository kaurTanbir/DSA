#include "testUtils.h"
#include "stack.h"
#include "memory.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
Stack* stack;



//---------------------push----------------------------------
void test_push_new_element_in_integer_stack (){
	int res;
    int newElement = 3;
    stack = create(3,sizeof(int));
	res = push(stack, &newElement);
	ASSERT(res == 1);
};


void test_increment_of_the_length_of_stack_if_stack_is_full(){
    int nums[2] = {23,15};
    int element = 12;
    int result;
    stack = create(2, sizeof(int));
    memcpy(stack->base, nums, sizeof(nums));
    stack->top = 2;
    result = push(stack, &element);
    ASSERT(1 == result);
}
void test_adds_the_given_Strings_at_the_top_of_the_stack(){
    String name = "tannu";
    int res;
    stack = create(1, sizeof(String));
    res = push(stack, &name);
    ASSERT(1 == res);
}
//--------------------------------pop---------------------------------------------
void test_pop_the_top_most_element_of_stack(){
    int a[4] = {1,2,3,4};
    int result;
    stack = create(4, sizeof(int));
    memcpy(stack->base,a,4*sizeof(int));
    stack->top = 4;
    result = *(int*)(pop(stack));
    ASSERT(4 == result);
};
void test_pop_the_element_of_empty_stack(){
    int a[4] = {};
    void* result;
    stack = create(4, sizeof(int));
    memcpy(stack->base,a,4*sizeof(int));
    stack->top = 0;
    result = (pop(stack));
    ASSERT(NULL == result);
};
void test_pop_the_element_from_a_string_stack(){
    String chars[4] = {"banana","mango","mango","apple"};
    char* result;
    String expected = "apple";
    stack = create(4, sizeof(String));
    memcpy(stack->base,chars,4*sizeof(String));
    stack->top = 4;
    result = (char*)(pop(stack));
    ASSERT(0==strcmp(result, expected));
};
//------------------------------peek---------------------------------------
void test_gives_the_top_most_element_of_stack(){
    int result;
    int nums[3] = {10,20,30};
    stack = create(5, sizeof(int));
    stack->top = 3;
    memcpy(stack->base,nums, 3*stack->elementSize);
    result = *(int*)peek(*stack);
    ASSERT(30 == result);
};
void test_gives_the_top_most_element_of_stack_String(){
    char* result;
    String fruits[3] = {"apple","mango","orange"};
    String expected = "orange";
    stack = create(5, sizeof(String));
    stack->top = 3;
    memcpy(stack->base, fruits, 3*stack->elementSize);
    result = (char*)peek(*stack);
    ASSERT(0==strcmp(expected, result));
};
