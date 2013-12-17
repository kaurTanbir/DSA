#include "testUtils.h"
#include "circular_queue.h"
#include <memory.h>
#include <stdlib.h>

Queue *queue;

void tearDown(){
	free(queue->base);
    free(queue);
}

//---------------------enqueue----------------------------------------
void test_inserts_an_Integer_element_in_queue(){
    int first = 1,
    	second = 2;
    int* res;
    queue = create(sizeof(int), 3);
    enqueue(queue,&first);
    enqueue(queue,&second);
    res = dequeue(queue);
    ASSERT(1 == *res);
}

void test_inserts_a_double_element_in_queue_at_rear_end(){
    double first = 1.0,
    		second= 2.0;
    double* res;
    queue = create(sizeof(double), 3);
    enqueue(queue,&first);
    enqueue(queue,&second);
    res = dequeue(queue);
    ASSERT(1.0 == *res);
}

void test_inserts__characters_in_queue_at_rear_end(){
    char first = 'a',
    	 second = 'b';
    char* res;
    queue = create(sizeof(char), 3);
    enqueue(queue,&first);
    enqueue(queue,&second);
    res = dequeue(queue);
    ASSERT('a' == *res);
}

void test_inserts_String_elements_in_queue_at_rear_end(){
    String name1 = "tannu",
		   name2 = "tanbir";
    String* res;
    queue = create(sizeof(String), 3);
    enqueue(queue,name1);
    enqueue(queue,name2);
    res = dequeue(queue);
    ASSERT(0 == strcmp("tannu",*res));
}
void test_returns_0_if_trying_to_enqueue_in_a_full_queue(){
    int res;
    String name1 = "tannu",
		   name2 = "tanbir",
		   name3 = "mannu";
    queue = create(sizeof(String), 2);
    enqueue(queue,name1);
    enqueue(queue,name2);
    res = enqueue(queue, name3);
    ASSERT(0 == res);
}
void test_returns_1_if_enqueued_in_the_stack(){
    int res;
    String name1 = "tannu";
    queue = create(sizeof(String), 2);
    res = enqueue(queue, name1);
    ASSERT(1 == res);
}
 
//----------------------------dequeue----------------------------------------

void test_returns_null_if_trying_to_dequeue_from_an_empty_queue(){
    queue = create(sizeof(String), 2);
    ASSERT(NULL == dequeue(queue));
}
