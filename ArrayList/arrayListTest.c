#include <stdlib.h>
#include "testUtils.h"
#include "arrayList.h"

const int SUCCESS = 1;
const int FAILURE = 0;

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct {
	int id;
	char* name;
	int age;
} Intern;

Intern prateek = {15386, "Prateek", 18};
Intern ji = {13432, "Immortal", 17};	
ArrayList interns;
ArrayList *internsPtr;

void setup() {
	int noOfElements = 2;	
	interns = create(noOfElements);
	internsPtr = &interns;
}

void tearDown() {
	dispose(internsPtr);	
}

void test_insert_element(){
	int result = insert(internsPtr, 0, &prateek);
	Intern *actual = (Intern*)get(*internsPtr, 0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
}

void test_insert_multiple_elements() {
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	ASSERT(&prateek == get(*internsPtr, 0));
	ASSERT(&ji == get(*internsPtr, 1));
}

void test_interns_grows_beyond_capacity() {
	int noOfElements = 1;
	ArrayList list = create(noOfElements);
	ArrayList *listPtr = &list;

	insert(listPtr, 0, &prateek);
	insert(listPtr, 1, &ji);

	ASSERT(&prateek == get(*listPtr, 0));
	ASSERT(&ji == get(*listPtr, 1));

	dispose(listPtr);		
}

void test_should_not_insert_at_index_beyond_length() {
	int result = FAILURE;
	result = insert(internsPtr, 2, &prateek);
	ASSERT(result == FAILURE);
}

void test_should_not_insert_at_negative_index() {
	int result = FAILURE;
	result = insert(internsPtr, -1, &prateek);
	ASSERT(result == FAILURE);
}

void test_insert_at_middle_should_shift_the_elements() {
	Intern tanbirka = {43343, "Tanbir Ka"};
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	insert(internsPtr, 1, &tanbirka);
	
	ASSERT(&prateek == get(*internsPtr, 0));
	ASSERT(&tanbirka == get(*internsPtr, 1));
	ASSERT(&ji == get(*internsPtr, 2));
}

void test_should_not_insert_when_list_is_null() {
	int result = insert(NULL, 1, &prateek);
	ASSERT(result == FAILURE);
}
void test_add_element(){
	int result = add(internsPtr,&prateek);
	Intern *actual = (Intern*)get(*internsPtr, 0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
}
void test_remove_element(){
	int result;
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &ji);
	result = remove(internsPtr,0);
	ASSERT(SUCCESS == result);
	ASSERT(&ji == get(*internsPtr, 0));
}
void test_remove_element_from_empty_list(){
	int result = remove(internsPtr,0);
	ASSERT(FAILURE == result);
}

void test_removes_and_shifts_elements_left(){
    int result;
    insert(internsPtr, 0, &prateek);
    insert(internsPtr, 1, &ji);
    result = remove(internsPtr, 0);
    ASSERT(&ji == get(interns, 0));
    ASSERT(NULL == get(interns, 1));
    ASSERT(result == SUCCESS);        
}
int compareInterns(void *intern1,void *intern2){
    Intern in1 = *(Intern*)intern1;
    Intern in2 = *(Intern*)intern2;
    return (in1.id - in2.id);
}
void test_should_get_index_of_search_element() {
    insert(internsPtr, 0, &prateek);
    insert(internsPtr, 1, &ji);
    ASSERT(0 == searchIndex(internsPtr, &prateek, compareInterns));
}
void test_should_get_minus_1_if_element_not_found() {
    insert(internsPtr, 0, &prateek);
    ASSERT(-1 == searchIndex(internsPtr, &ji, compareInterns));
}
void test_iterator_tells_that_next_data_is_present(){
    Iterator it;
    insert(internsPtr, 0, &prateek);
    it = getIterator(internsPtr);
    ASSERT(1 == it.hasNext(&it));
}

void test_iterator_tells_that_next_data_is_not_present(){
    Iterator it;
    it = getIterator(internsPtr);
    ASSERT(0 == it.hasNext(&it));
}

void test_iterator_gives_the_data_of_next_index(){
    Iterator it;
    insert(internsPtr, 0, &prateek);
    insert(internsPtr, 0, &ji);
    it = getIterator(internsPtr);
    ASSERT(&ji == it.next(&it));
    ASSERT(&prateek == it.next(&it));
    ASSERT(NULL == it.next(&it));
}

void printId(void* data){
        Intern intern = *(Intern*)data;
        printf("%d\n", intern.id);
}

void test_prints_data_of_each_element(){
        add(internsPtr, &prateek);
        add(internsPtr, &ji);
        iterate(interns, printId);
}