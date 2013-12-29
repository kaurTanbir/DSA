#include "testUtils.h"
#include "b_sort.h"
#include <string.h>
#include <stdlib.h>

typedef char String[50];

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


int compareIntegers ( void* a,  void* b){
    return (*(int*)a - *(int*)b);
}




void test_sort_Int_array(){
    int data[] = {4,3,1,2,5};
    int expected[] = {1,2,3,4,5};
    sort(data, 5, sizeof(int), compareIntegers);
    ASSERT(0 == memcmp(expected, data, sizeof(expected)));
}

