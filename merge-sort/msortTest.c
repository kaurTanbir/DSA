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
typedef struct {
	int Acc_no;
	double balance;
} Account;
//--------------------------------------------------------------------------------------

int compareAccounts(void* first, void* second) {
    Account* firstAccount = (Account*)first;
    Account* secondAccount = (Account*)second;
    return firstAccount->Acc_no - secondAccount->Acc_no;
}

int compareIntegers ( void* a,  void* b){
    return (*(int*)a - *(int*)b);
}

int compareDoubles( void* a,  void* b){
    return (*(double*)a - *(double*)b);
}

int compareCharacters( void* a,  void* b){
    return (*(char*)a - *(char*)b);
}

int compareStrings( void* a,  void* b){
    return strcmp((char*)a,(char*)b);
}

//------------------------------------------------------------------------------------------

void test_sorts_array_of_Integers_odd_(){
    int nums[5] = {1,2,3,4,5};
    void* arrayToSort[5] = {&nums[4],&nums[3],&nums[2],&nums[1],&nums[0]};
    void* expected[5] = {&nums[0],&nums[1],&nums[2],&nums[3],&nums[4]};
    sort(arrayToSort, 5, compareIntegers);
    ASSERT(areArrayEqual(arrayToSort, expected, 5));
}
void test_sorts_array_of_Integers_even_(){
    int nums[4] = {1,2,3,4};
    void* arrayToSort[4] = {&nums[3],&nums[2],&nums[1],&nums[0]};
    void* expected[4] = {&nums[0],&nums[1],&nums[2],&nums[3]};
    sort(arrayToSort, 4, compareIntegers);
    ASSERT(areArrayEqual(arrayToSort, expected, 4));
}


void test_sorts_array_of_doubles(){
    double nums[5] = {1.0,2.0,3.0,4.0,5.0};
    void* arrayToSort[5] = {&nums[4],&nums[3],&nums[2],&nums[1],&nums[0]};
    void* expected[5] = {&nums[0],&nums[1],&nums[2],&nums[3],&nums[4]};
    sort(arrayToSort, 5, compareIntegers);
    ASSERT(areArrayEqual(arrayToSort, expected, 5));
}
void test_sorts_array_of_Characters(){
    char chars[5] = {'a','b','c','d','e'};
    void* arrayToSort[5] = {(chars+3),(chars+1),(chars+4),(chars+2),(chars)};
    void* expected[5] = {(chars+0),(chars+1),(chars+2),(chars+3),(chars+4)};
    sort(arrayToSort, 5, compareCharacters);
    ASSERT(areArrayEqual(arrayToSort, expected, 5));
}
void test_sorts_array_of_String(){
    String names[5] = {"aaaa","bbbb","cccc","dddd","eeee"};
    void* arrayToSort[5] = {(names+3),(names+1),(names+4),(names+2),(names)};
    void* expected[5] = {(names+0),(names+1),(names+2),(names+3),(names+4)};
    sort(arrayToSort, 5, compareStrings);
    ASSERT(areArrayEqual(arrayToSort, expected, 5));
}
void test_sorts_Accounts_according_to_account_number(){
    Account accounts[] = {{1, 10} , {2,100}, {3, 1000}, {4, 10}, {5, 100}};
    void* account[5] = {(accounts+3),(accounts+1),(accounts+4),(accounts+2),(accounts)};
    void* expected[5] = {(accounts+0),(accounts+1),(accounts+2),(accounts+3),(accounts+4)};
    sort(account, 5, compareAccounts);
    ASSERT(areArrayEqual(account, expected, 5));
}

