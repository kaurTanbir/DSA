#include "testUtils.h"
#include "linkList.h"
#include <stdlib.h>
#include <memory.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
DList* list;

void tearDown(){
        free(list);
}
void test_gives_an_Doubly_link_list_with_head_NULL(){
        list = create();
        ASSERT(NULL == list->head);
        ASSERT(0 == list->length);
}

void test_create_node(){
    Node expected = {NULL,NULL,NULL};
    Node *actual = createNode(NULL,NULL);
    ASSERT(expected.next == actual->next);
    ASSERT(expected.prev == actual->prev);
}

void test_inserts_an_element_at_begining_of_list(){
        int* num = malloc(sizeof(int));
        list = create();
        *num = 10;
        insertNode(list, num, 0);
        ASSERT(10 == *(int*)list->head->data);
        ASSERT(NULL == list->head->prev);
        ASSERT(NULL == list->head->next);
        ASSERT(1 == list->length);
}

void test_inserts_element_at_the_end_of_linkList(){
        int* arr = malloc(sizeof(int)*3);
        Node *res1,*res2;
        list = create();
        arr[0] = 1;arr[1] = 2;arr[2] = 3;

        insertNode(list, &arr[0], 0);
        insertNode(list, &arr[1], 1);
        res1 = list->head->next;
        insertNode(list, &arr[2], 2);
        res2 = res1->next;
        ASSERT(3 == *(int*)res2->data);
        ASSERT(res1 == res2->prev);
        ASSERT(NULL == res2->next);
        ASSERT(3 == list->length);
}

void test_adds_element_in_middle_of_linkList(){
    Node *second;
    int* arr = malloc(sizeof(int)*3);
    arr[0] = 1;arr[1] = 2;arr[2] = 3;
    list = create();
    insertNode(list, &arr[1], 0);
    insertNode(list, &arr[0], 0);
    second = list->head->next;
    ASSERT(1 == *(int*)list->head->data);
    ASSERT(2 == *(int*)second->data);
}
void test_deletes_first_element_in_list(){
    int* num = malloc(sizeof(int));
    *num = 1;
           list = create();
    insertNode(list, num, 0);
    ASSERT(deleteNode(list, 0));
    ASSERT(0 == list->length);
    ASSERT(NULL == list->head);
}

void test_deletes_last_element_in_the_list(){
    int* arr = malloc(sizeof(int)*2);
        list = create();
        arr[0] = 1;arr[1] = 2;
    insertNode(list,&arr[0], 0);
    insertNode(list,&arr[1], 1);
    ASSERT(deleteNode(list, 1));
    ASSERT(1 == list->length);
    ASSERT(NULL == list->head->next);
}

void test_deletes_element_in_between_the_list(){
    int* arr = malloc(sizeof(int)*3);
        list = create();
        arr[0] = 1;arr[1] = 2;arr[2] = 3;
    insertNode(list,&arr[0], 0);
    insertNode(list,&arr[1], 1);
    insertNode(list,&arr[2], 2);
    ASSERT(deleteNode(list, 1));
    ASSERT(2 == list->length);
    ASSERT(3 == *(int*)list->head->next->data);
}