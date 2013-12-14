#include "testUtils.h"
#include "priorityQueue.h"
#include "testUtils.h"
#include <memory.h>
#include <stdlib.h>

Queue *queue;

void tearDown(){
	free(queue->base);
    free(queue);
}
int areEqual(Queue a, Queue b){
        int result = a.length == b.length && a.front == b.front
                                && a.rear == b.rear &&  a.elementSize == b.elementSize ;
        if(!result) return result;
        return 0 == memcmp(a.base,b.base,a.length*a.elementSize);
}
//----------------------------------compare function-----------------------------
int compareInt ( void* a,  void* b){
    return (*(int*)a - *(int*)b);
}

int compareDouble( void* a,  void* b){
    return (*(double*)a - *(double*)b);
}

int compareChars( void* a,  void* b){
    return (*(char*)a - *(char*)b);
}

int compareStrings( void* a,  void* b){
    return strcmp((char*)a,(char*)b);
}


//---------------------Penqueue----------------------------------------

void test_inserts_an_Integer_element_in_queue(){
        int int_arr[2] = {1,2};
        int first = 2,
        	second = 1;
        Queue expected = {int_arr,2,sizeof(int),1,0};
        queue = create(sizeof(int), 2);
        Penqueue(queue,&first,compareInt);
        Penqueue(queue,&second,compareInt);
        ASSERT(areEqual(expected, *queue));
}
void test_inserts_a_double_element_in_queue_at_rear_end(){
        double double_arr[3] = {1.0,2.0,3.0};
        double first = 2.0,
        		second= 3.0,
                third = 1.0;
        Queue expected = {double_arr,3,sizeof(double),2,0};
        queue = create(sizeof(double), 3);
        Penqueue(queue,&first,compareDouble);
        Penqueue(queue,&second,compareDouble);
        Penqueue(queue,&third,compareDouble);
        ASSERT(areEqual(expected, *queue));
}

void test_inserts__characters_in_queue_at_rear_end(){
        char chars_arr[3] = {'a','b','\0'};
        char first = 'a',
        	 second = 'b';
        Queue expected = {chars_arr,3,sizeof(char),1,0};
        queue = create(sizeof(char), 3);
        Penqueue(queue,&first,compareChars);
        Penqueue(queue,&second,compareChars);
        ASSERT(areEqual(expected, *queue));
}

void test_inserts_String_elements_in_queue_at_rear_end(){
        String string_arr[3] = {"tanbir","tannu",""};
        String name1 = "tannu",
			   name2 = "tanbir";
        Queue expected = {string_arr,3,sizeof(String),1,0};
        queue = create(sizeof(String), 3);
        Penqueue(queue,name1,compareStrings);
        Penqueue(queue,name2,compareStrings);
        ASSERT(areEqual(expected, *queue));
}
void test_returns_0_if_trying_to_Penqueue_in_a_full_queue(){
        int res;
        String name1 = "tannu",
			   name2 = "tanbir",
			   name3 = "mannu";
        queue = create(sizeof(String), 2);
        Penqueue(queue,name1,compareStrings);
        Penqueue(queue,name2,compareStrings);
        res = Penqueue(queue, name3,compareStrings);
        ASSERT(0 == res);
}
void test_returns_1_if_Penqueued_in_the_stack(){
        int res;
        String name1 = "tannu";
        queue = create(sizeof(String), 2);
        res = Penqueue(queue, name1,compareStrings);
        ASSERT(1 == res);
}
