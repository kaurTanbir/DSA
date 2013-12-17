#include "testUtils.h"
#include "bsearch.h"
//--------------------compare functions------------------------------------

int compareInt ( void* a,  void* b){
    return (*(int*)a - *(int*)b);
}

int compareDouble( void* a,  void* b){
    return (*(double*)a - *(double*)b);
}

int compareChars( void* a,  void* b){
    return (*(char*)a - *(char*)b);
}

int compareStrings( void* a,  void* b){
    return strcmp((char*)a,(char*)b);
}

//-------------------------integers-------------------------------------------------

void test_1_search_element_in_integer_array(){
    int elements[4] = {1,2,3,4};
    int key = 2;
    int* result = binarySearch(&key, elements, 4, sizeof(int), compareInt);
    ASSERT(2 == *result);
}
void test_2_search_last_element_in_integer_array(){
        int elements[4] = {1,2,3,4};
        int key = 4;
        int* result = binarySearch(&key, elements, 4, sizeof(int), compareInt);
        ASSERT(4 == *result);
}
void test_3_search_first_element_in_integer_array(){
        int elements[4] = {1,2,3,4};
        int key = 1;
        int* result = binarySearch(&key, elements, 4, sizeof(int), compareInt);
        ASSERT(1 == *result);
}
void test_4_gives_NULL_if_element_is_not_present(){
        int elements[4] = {1,2,3,4};
        int key = 5;
        int* result = binarySearch(&key, elements,4 , sizeof(int), compareInt);
        ASSERT(NULL == result);
}
//--------------------------double-----------------------------------------------------
void test_5_search_element_in_double_array(){
    double elements[4] = {1.0,2.0,3.0,4.0};
    double key = 2.0;
    double* result = binarySearch(&key, elements, 4, sizeof(double), compareDouble);
    ASSERT(2.0 == *result);
}
void test_6_search_last_element_in_double_array(){
        double elements[4] = {1.0,2.0,3.0,4.0};
        double key = 4.0;
        double* result = binarySearch(&key, elements, 4, sizeof(double), compareDouble);
        ASSERT(4.0 == *result);
}
void test_7_search_first_element_in_double_array(){
        double elements[4] = {1.0,2.0,3.0,4.0};
        double key = 1.0;
        double* result = binarySearch(&key, elements, 4, sizeof(double), compareDouble);
        ASSERT(1.0 == *result);
}
void test_8_gives_NULL_if_element_is_not_present(){
        double elements[4] = {1.0,2.0,3.0,4.0};
        double key = 5.0;
        double* result = binarySearch(&key, elements,4 , sizeof(double), compareDouble);
        ASSERT(NULL == result);
}
//--------------------------------chars-----------------------------------------
void test_9_search_element_in_char_array(){
    char elements[4] = {'a','b','c','d'};
    char key = 'c';
    char* result = binarySearch(&key, elements, 4, sizeof(char), compareChars);
    ASSERT('c' == *result);
}
void test_10_search_last_element_in_char_array(){
        char elements[4] = {'a','b','c','d'};
        char key = 'd';
        char* result = binarySearch(&key, elements, 4, sizeof(char), compareChars);
        ASSERT('d' == *result);
}
void test_11_search_first_element_in_char_array(){
        char elements[4] = {'a','b','c','d'};
        char key = 'a';
        char* result = binarySearch(&key, elements, 4, sizeof(char), compareChars);
        ASSERT('a'== *result);
}
void test_12_gives_NULL_if_element_is_not_present(){
        char elements[4] = {'a','b','c','d'};
        char key = 'f';
        char* result = binarySearch(&key, elements,4 , sizeof(char), compareChars);
        ASSERT(NULL == result);
}
//--------------------------------string-------------------------------------------------
void test_13_search_element_in_char_array(){
    String elements[4] = {"abc","bcd","cde","def"};
    String key = "cde";
    String* result = binarySearch(&key, elements, 4, sizeof(String), compareStrings);
    ASSERT(strcmp("cde",*result) == 0);
}
void test_14_search_last_element_in_String_array(){
        String elements[4] =  {"abc","bcd","cde","def"};
        String key = "def";
        String* result = binarySearch(&key, elements, 4, sizeof(String), compareStrings);
        
        ASSERT(strcmp("def",*result) == 0);
}
void test_15_search_first_element_in_String_array(){
        String elements[4] =  {"abc","bcd","cde","def"};
        String key = "abc";
        String* result = binarySearch(&key, elements, 4, sizeof(String), compareStrings);
        ASSERT(strcmp("abc",*result) == 0);
}
void test_16_gives_NULL_if_element_is_not_present(){
        String elements[4] =  {"abc","bcd","cde","def"};
        String key = "fgh";
        String* result = binarySearch(&key, elements,4 , sizeof(String), compareStrings);
        ASSERT(NULL == result);
}