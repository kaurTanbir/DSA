#include "testUtils.h"
#include "msort.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int areArrayEqual(void** a,void** b, int length){
    int i;
    for(i = 0;i<length;i++){
        if(a[i] != b[i])
            return 0;
    }
    return 1;
}

//--------------------------------------------------------------------------------------



int compareIntegers ( void* a,  void* b){
    return (*(int*)a - *(int*)b);
}

int compareDoubles( void* a,  void* b){
    return (*(double*)a - *(double*)b);
}



//------------------------------------------------------------------------------------------

void test_sorts_array_of_Integers(){
    int nums[5] = {1,2,3,4,5};
    void* arrayToSort[5] = {&nums[4],&nums[3],&nums[2],&nums[1],&nums[0]};
    void* expected[5] = {&nums[0],&nums[1],&nums[2],&nums[3],&nums[4]};
    sort(arrayToSort, 5, compareIntegers);
    ASSERT(areArrayEqual(arrayToSort, expected, 5));
}
void test_sorts_array_of_doubles(){
    double nums[5] = {1.0,2.0,3.0,4.0,5.0};
    void* arrayToSort[5] = {&nums[4],&nums[3],&nums[2],&nums[1],&nums[0]};
    void* expected[5] = {&nums[0],&nums[1],&nums[2],&nums[3],&nums[4]};
    sort(arrayToSort, 5, compareIntegers);
    ASSERT(areArrayEqual(arrayToSort, expected, 5));
}
