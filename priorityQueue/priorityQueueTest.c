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

//---------------------Penqueue----------------------------------------

void test_inserts_an_Integer_element_in_queue(){
    int first = 1,
        second = 2;

    data_specification* res;
    data_specification* element1 = malloc(sizeof(data_specification));
    data_specification* element2 = malloc(sizeof(data_specification));
    
    element1->data = &first;
    element1->priority = 2;
    
    element2->data = &second;
    element2->priority = 1;
    
    queue = create(sizeof(data_specification), 2);
    
    Penqueue(queue,element1);
    Penqueue(queue,element2);
    
    res = queue->base;
    
    ASSERT(element2->priority == res->priority);
    ASSERT(element2->data == res->data);
    ASSERT(element1->priority == (res+queue->elementSize)->priority);
    ASSERT(element1->data == (res+queue->elementSize)->data);
}
void test_inserts_an_Integer_element_inbetween_queue(){
    int first = 1,
        second = 2;

    data_specification* res;
    data_specification* element1 = malloc(sizeof(data_specification));
    data_specification* element2 = malloc(sizeof(data_specification));
    data_specification* element3 = malloc(sizeof(data_specification));

    element1->data = &first;
    element1->priority = 4;
    
    element2->data = &second;
    element2->priority = 2;
    
    element3->data = &second;
    element3->priority = 3;
    
    queue = create(sizeof(data_specification), 4);
    
    Penqueue(queue,element1);
    Penqueue(queue,element2);
    
    res = queue->base;
    ASSERT(element2->priority == res->priority);
}

void test_inserts_an_Integer_element_at_begining_of_queue(){
    int first = 1;

    data_specification* res;
    data_specification* element1 = malloc(sizeof(data_specification));

    element1->data = &first;
    element1->priority = 1;

    queue = create(sizeof(data_specification), 1);
    Penqueue(queue,element1);

    res = queue->base;
    ASSERT(element1->priority == res->priority);
    ASSERT(element1->data == res->data);
}
void test_returns_1_when_successfully_entered_inqueue(){
    int first = 1,res;

    data_specification* element1 = malloc(sizeof(data_specification));

    element1->data = &first;
    element1->priority = 1;

    queue = create(sizeof(data_specification), 1);
    res = Penqueue(queue,element1);

    ASSERT(1 == res);

}
void test_gives_0_if_trying_to_enqueue_in_full_queue(){
    int first = 1, result;

    data_specification* element1 = malloc(sizeof(data_specification));

    element1->data = &first;
    element1->priority = 1;

    queue = create(sizeof(data_specification), 1);
    Penqueue(queue,element1);
    result = Penqueue(queue,element1);
    ASSERT(0 == result);
}
void test_gives_highest_priority_element_on_dequeue(){
    int first = 1,
            second = 2;

    data_specification* res;
    data_specification* element1 = malloc(sizeof(data_specification));
    data_specification* element2 = malloc(sizeof(data_specification));
    
    element1->data = &first;
    element1->priority = 2;
    
    element2->data = &second;
    element2->priority = 1;
    
    queue = create(sizeof(data_specification), 2);
    
    Penqueue(queue,element1);
    Penqueue(queue,element2);
    
    res = dequeue(queue);
    ASSERT(element2->priority == res->priority);
}