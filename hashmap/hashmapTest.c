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
    HashMap map = createMap(hashGenerator, areKeysEqual,10);
    res = put(&map, &tanbirka.key, &tanbirka.value);
    ASSERT(1 == res);
}
void test_add_second_element_to_hashmap_in_same_bucket(){
	int res;
    HashMap map = createMap(hashGenerator, areKeysEqual,10);
    res = put(&map, &ji.key, &ji.value);
    ASSERT(1 == res);
}

void test_add_gives_NULL_when_hash_map_is_null(){
        ASSERT(0 == put(NULL,&ji.key,&ji));
};

void test_add_gives_NULL_when_key_is_null(){
        HashMap map = createMap(hashGenerator,areKeysEqual,10);
        ASSERT(0 == put(&map,NULL,&tanbirka));        
};

void test_add_updates_the_value_of_key_if_already_present(){
    Intern tannu ={15440,"tannu"};
    Iterator it;
    HashMap map = createMap(hashGenerator, areKeysEqual,10);
    put(&map, &ji.key, &ji);
    ASSERT(&ji == get(&map, &ji.key));
    put(&map, &tannu.key, &tannu);
    ASSERT(&tannu == get(&map, &ji.key));
}
void test_get_an_element_from_hashMap(){
    HashMap map = createMap(hashGenerator, areKeysEqual,10);
    ASSERT(put(&map, &tanbirka.key, &tanbirka.value));
    ASSERT(0 == strcmp((char*)get(&map, &tanbirka.key),tanbirka.value));
}

void test_get_gives_NULL_when_key_is_not_present(){
    HashMap map = createMap(hashGenerator, areKeysEqual,10);
    ASSERT(NULL == get(&map, &ji.key));
}
void test_get_gives_NULL_when_map_is_null(){
    ASSERT(NULL == get(NULL,&tanbirka.key));

};
void test_get_gives_NULL_when_key_is_null(){
    HashMap map = createMap(hashGenerator, areKeysEqual,10);
    ASSERT(NULL == get(&map,NULL));
};
void test_deletes_the_value_matched_to_given_key(){
    HashMap map = createMap(hashGenerator, areKeysEqual,10);
    ASSERT(put(&map,&ji.key , &ji));
    ASSERT(remove(&map, &ji.key));
    ASSERT(NULL == get(&map, &ji.key));        
}
void test_deletion_failed_when_key_is_not_present(){
    HashMap map = createMap(hashGenerator, areKeysEqual,10);
    ASSERT(0 == remove(&map, &tanbirka.key));
    ASSERT(NULL == get(&map, &tanbirka.key));        
}
void test_deleting_element_which_is_not_present(){
    HashMap map = createMap(hashGenerator, areKeysEqual,10);
    ASSERT(0 == remove(&map,&tanbirka));
};

void test_deleting_when_key_is_null_gives_NULL(){
    HashMap map = createMap(hashGenerator, areKeysEqual,10);
    ASSERT(0 == remove(&map,NULL));

};
void test_deleting_when_map_is_null_gives_NULL(){
    ASSERT(0 == remove(NULL,NULL));
}

void test_iterating_over_hash_map(){
    HashMap map = createMap(hashGenerator,areKeysEqual,10);
    Iterator it;
    put(&map,&tanbirka.key,&tanbirka);
    put(&map,&ji.key,&ji);
    it = getAllKeys(map);
    ASSERT(ji.key == *(int*)it.next(&it));
    ASSERT(tanbirka.key == *(int*)it.next(&it));
    ASSERT(NULL == it.next(&it));
};

void test_iterating_when_no_more_elements_are_present(){
    HashMap map = createMap(hashGenerator,areKeysEqual,10);
    Iterator it;
    it = getAllKeys(map);
    ASSERT(NULL == it.next(&it));
};
