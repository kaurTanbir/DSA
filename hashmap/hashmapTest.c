#include "testUtils.h"
#include "hashmap.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areKeysEqual(void* key1 , void* key2 ){
    if(*(int*)key1 == *(int*)key2)
    	return 1;
    return 0;
}
int hashGenerator(void *key){
    return *(int*)key;
};

typedef struct{
    int key;
    char value[20];
} Intern;
Intern tanbirka = {15450,"tanbirka"};
Intern ji = {15440,"ji"};


void test_add_an_element_to_hashmap(){
	int res;
    HashMap map = createMap(hashGenerator, areKeysEqual);
    res = put(&map, &tanbirka.key, &tanbirka.value);
    ASSERT(1 == res);
}
void test_add_second_element_to_hashmap_in_same_bucket(){
	int res;
    HashMap map = createMap(hashGenerator, areKeysEqual);
    res = put(&map, &ji.key, &ji.value);
    ASSERT(1 == res);
}
void test_add_an_element_to_hashmap_and_get_it(){
    HashMap map = createMap(hashGenerator, areKeysEqual);
    ASSERT(put(&map, &tanbirka.key, &tanbirka.value));
    ASSERT(0 == strcmp((char*)get(map, &tanbirka.key),tanbirka.value));
}
