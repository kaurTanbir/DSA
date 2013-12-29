#include "testUtils.h"
#include "b_sort.h"
#include <string.h>
#include <stdlib.h>

typedef char String[50];

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


int compareIntegers ( void* a,  void* b){
    return (*(int*)a - *(int*)b);
}
int compareDoubles( void* a,  void* b){
    return (*(double*)a - *(double*)b);
}
int compareCharacters( void* a,  void* b){
    return (*(char*)a - *(char*)b);
}
void test_sort_Int_array(){
    int data[] = {4,3,1,2,5};
    int expected[] = {1,2,3,4,5};
    sort(data, 5, sizeof(int), compareIntegers);
    ASSERT(0 == memcmp(expected, data, sizeof(expected)));
}
void test_sort_double_array(){
    double data[] = {4.0,3.0,1.0,2.0,5.0};
    double expected[] = {1.0,2.0,3.0,4.0,5.0};
    sort(data, 5, sizeof(double), compareDoubles);
    ASSERT(0 == memcmp(expected, data, sizeof(expected)));
}
void test_sort_character_array(){
    char data[] = {'d','c','a','e','b'};
    char expected[] = {'a','b','c','d','e'};
    sort(data, 5, sizeof(char), compareCharacters);
    ASSERT(0 == memcmp(expected, data, sizeof(expected)));
}
