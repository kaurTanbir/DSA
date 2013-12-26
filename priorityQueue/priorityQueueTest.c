#include "testUtils.h"
#include "priorityQueue.h"
#include "testUtils.h"
#include <memory.h>
#include <stdlib.h>

PriorityQueue *queue;

// void tearDown(){
// 	free(queue->elements);
//     free(queue);
// }

//---------------------Penqueue----------------------------------------

void test_inserts_an_Integer_element_in_queue(){
    int first = 1;

    data_specification* element1 = malloc(sizeof(data_specification));
    
    element1->data = &first;
    element1->priority = 2;
    
    queue = createPQ(sizeof(data_specification), 2);
    
    ASSERT(1 == Penqueue(queue,element1));
}


void test_returns_1_when_successfully_entered_inqueue(){
    int first = 1,res;

    data_specification* element1 = malloc(sizeof(data_specification));

    element1->data = &first;
    element1->priority = 1;

    queue = createPQ(sizeof(data_specification), 1);
    res = Penqueue(queue,element1);

    ASSERT(1 == res);

}
void test_gives_0_if_trying_to_enqueue_in_full_queue(){
    int first = 1, result;

    data_specification* element1 = malloc(sizeof(data_specification));

    element1->data = &first;
    element1->priority = 1;

    queue = createPQ(sizeof(data_specification), 1);
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
    
    queue = createPQ(sizeof(data_specification), 2);
    
    Penqueue(queue,element1);
    Penqueue(queue,element2);
    
    res = dequeuePQ(queue);
    ASSERT(element2->priority == res->priority);
}