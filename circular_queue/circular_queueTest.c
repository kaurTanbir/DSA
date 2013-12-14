#include "testUtils.h"
#include "circular_queue.h"
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
//---------------------------create-----------------------------------------------

void test_creates_a_queue_of_integers(){
        int arr[2] = {0,0};
        Queue expected = {arr,2,sizeof(int),-1,-1};
        queue = create(sizeof(int),2);
        ASSERT(areEqual(expected, *queue));
};

void test_creates_a_queue_of_doubles (){
        double arr[3] = {0.0,0.0,0.0};
        Queue expected = {arr,3,sizeof(double),-1,-1};
        queue = create(sizeof(double), 3);
        ASSERT(areEqual(expected, *queue));
};

void test_creates_a_queue_of_characters (){
        char arr_null[3] = {'\0','\0','\0'};
        Queue expected = {arr_null,3,sizeof(char),-1,-1};
        queue = create(sizeof(char),3);
        ASSERT(areEqual(expected, *queue));
};

void test_creates_a_queue_of_strings (){
        String arr_blank[3] = {"","",""};
        Queue expected = {arr_blank,3,sizeof(String),-1,-1};
        queue = create(sizeof(String),3);
        ASSERT(areEqual(expected, *queue));
};
//---------------------enqueue----------------------------------------
void test_inserts_an_Integer_element_in_queue(){
        int int_arr[3] = {1,2,0};
        int first = 1,
        	second = 2;
        Queue expected = {int_arr,3,sizeof(int),1,0};
        queue = create(sizeof(int), 3);
        enqueue(queue,&first);
        enqueue(queue,&second);
        ASSERT(areEqual(expected, *queue));
}
void test_inserts_an_double_element_in_queue(){
        int int_arr[3] = {1,2,0};
        int first = 1,
        	second = 2;
        Queue expected = {int_arr,3,sizeof(int),1,0};
        queue = create(sizeof(int), 3);
        enqueue(queue,&first);
        enqueue(queue,&second);
        ASSERT(areEqual(expected, *queue));
}void test_inserts_a_double_element_in_queue_at_rear_end(){
        double double_arr[3] = {1.0,2.0,0.0};
        double first = 1.0,
        		second= 2.0;
        Queue expected = {double_arr,3,sizeof(double),1,0};
        queue = create(sizeof(double), 3);
        enqueue(queue,&first);
        enqueue(queue,&second);
        ASSERT(areEqual(expected, *queue));
}

void test_inserts__characters_in_queue_at_rear_end(){
        char chars_arr[3] = {'a','b','\0'};
        char first = 'a',
        	 second = 'b';
        Queue expected = {chars_arr,3,sizeof(char),1,0};
        queue = create(sizeof(char), 3);
        enqueue(queue,&first);
        enqueue(queue,&second);
        ASSERT(areEqual(expected, *queue));
}

void test_inserts_String_elements_in_queue_at_rear_end(){
        String string_arr[3] = {"tannu","tanbir",""};
        String name1 = "tannu",
			   name2 = "tanbir";
        Queue expected = {string_arr,3,sizeof(String),1,0};
        queue = create(sizeof(String), 3);
        enqueue(queue,name1);
        enqueue(queue,name2);
        ASSERT(areEqual(expected, *queue));
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
//-----------------------queueIsFull--------------------------------------

void test_if_queue_is_full_returns_1(){
	int element1 = 1,
		element2 = 2,res;
	queue = create(sizeof(int),2);
	enqueue(queue, &element1);
	enqueue(queue, &element2);
	res = queueIsFull(queue);
	ASSERT(1 == res);
}
void test_if_queue_is_not_full_returns_0(){
	int element1 = 1,
		res;
	queue = create(sizeof(int),2);
	enqueue(queue, &element1);
	res = queueIsFull(queue);
	ASSERT(0 == res);
}
void test_if_rear_and_front_are_coresponding_to_eachother_queue_is_full(){
	String string_arr[3] = {"tannu","tanbir",""};
    String name1 = "tannu",
		   name2 = "tanbir";
    Queue expected = {string_arr,3,sizeof(String),0,1};
	int res; 
	queue = create(1, 1);
    res = queueIsFull(&expected);
    ASSERT(1 == res);
}
//----------------------------dequeue----------------------------------------
void test_dequeues_the_first_element_of_queue_of_integers(){
	int* res;
    int first = 1,
    	second = 2;
	queue = create(sizeof(int), 3);
	enqueue(queue, &first);
	enqueue(queue, &second);
	res = dequeue(queue);
	ASSERT(1 == *res);
	ASSERT(1 == queue->front);
}
void test_dequeues_the_first_element_of_queue_of_doubles(){
	float* res;
    float first = 1.0,
    	  second = 2.0;
	queue = create(sizeof(float), 3);
	enqueue(queue, &first);
	enqueue(queue, &second);
	res = dequeue(queue);
	ASSERT(1.0 == *res);
}
void test_dequeues_the_first_element_of_queue_of_characters(){
	char* res;
    char first = 'a',
    	 second = 'b';
	queue = create(sizeof(char), 3);
	enqueue(queue, &first);
	enqueue(queue, &second);
	res = dequeue(queue);
	ASSERT('a' == *res);
}
void test_dequeues_the_first_element_of_queue_of_strings(){
	String* res;
    String name1 = "annu",
    	   name2 = "tannu";
	queue = create(sizeof(String), 3);
	enqueue(queue, &name1);
	enqueue(queue, &name2);
	res = dequeue(queue);
	ASSERT(strcmp("annu",*res)== 0);
}
void test_returns_null_if_trying_to_dequeue_from_an_empty_queue(){
        queue = create(sizeof(String), 2);
        ASSERT(NULL == dequeue(queue));
}
//----------------------------queueIsEmpty----------------------------------
void test_if_queue_is_empty_returns_1(){
	int	res;
	queue = create(sizeof(int),2);
	res = queueIsEmpty(queue);
	ASSERT(1 == res);
}
void test_if_queue_is_not_empty_returns_0(){
	int element1 = 1,
		res;
	queue = create(sizeof(int),2);
	enqueue(queue, &element1);
	res = queueIsEmpty(queue);
	ASSERT(0 == res);
}
