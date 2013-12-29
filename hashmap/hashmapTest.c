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
void test_gives_NULL_when_key_is_not_present(){
    int key = 15;
    HashMap map = createMap(hashGenerator, areKeysEqual);
    ASSERT(NULL == get(map, &key));
}

void test_deletes_the_value_matched_to_given_key(){
    HashMap map = createMap(hashGenerator, areKeysEqual);
    ASSERT(put(&map,&ji.key , &ji));
    ASSERT(remove(&map, &ji.key));
    ASSERT(NULL == get(map, &ji.key));        
}
void test_deletion_failed_when_key_is_not_present(){
    HashMap map = createMap(hashGenerator, areKeysEqual);
    ASSERT(0 == remove(&map, &tanbirka.key));
    ASSERT(NULL == get(map, &tanbirka.key));        
}
void test_updates_the_value_of_key_if_is_already_present(){
    Intern tannu ={15440,"tannu"};
    Iterator it;
    HashMap map = createMap(hashGenerator, areKeysEqual);
    put(&map, &ji.key, &ji);
    ASSERT(&ji == get(map, &ji.key));
    put(&map, &tannu.key, &tannu);
    ASSERT(&tannu == get(map, &ji.key));
}

