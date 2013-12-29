#include "testUtils.h"
#include "b_sort.h"
#include <string.h>
#include <stdlib.h>


//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct {
	int Acc_no;
	double balance;
} Account;
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
void test_sort_string_array(){
	int i;
    String data[] = {"dddd","cccc","aaaa","eeee","bbbb"};
    String expected[] = {"aaaa","bbbb","cccc","dddd","eeee"};
    sort(data, 5, sizeof(String), compareStrings);
    ASSERT(0 == memcmp(expected, data, sizeof(expected)));
}
void test_sort_struct_array(){
	int i;
	Account acc1 = {1,100};
	Account acc2 = {2,100};
    Account data[] = {acc2,acc1};
    Account expected[] = {acc1,acc2};
    sort(data, 2, sizeof(Account), compareAccounts);
    ASSERT(0 == memcmp(expected, data, sizeof(expected)));
}