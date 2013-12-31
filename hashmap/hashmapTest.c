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
//-----------------------------------------------------------------------------
HashMap map;
void tearDown(){
    disposeMap(&map);
}
void setup(){
    map = createMap(hashGenerator, areKeysEqual,10);
}


typedef struct{
    int key;
    char value[20];
} Intern;
Intern tanbirka = {15450,"tanbirka"};
Intern ji = {15440,"ji"};

//--------------------------------------------------------------------------------------

void test_add_an_element_to_hashmap(){
	int res;
    res = putHashData(&map, &tanbirka.key, &tanbirka.value);
    ASSERT(1 == res);
}
void test_add_second_element_to_hashmap_in_same_bucket(){
	int res;
    res = putHashData(&map, &ji.key, &ji.value);
    ASSERT(1 == res);
}

void test_add_gives_NULL_when_hash_map_is_null(){
        ASSERT(0 == putHashData(NULL,&ji.key,&ji));
};

void test_add_gives_NULL_when_key_is_null(){
        ASSERT(0 == putHashData(&map,NULL,&tanbirka));        
};

void test_add_updates_the_value_of_key_if_already_present(){
    Intern tannu ={15440,"tannu"};
    Iterator it;
    putHashData(&map, &ji.key, &ji);
    ASSERT(&ji == getHashValue(&map, &ji.key));
    putHashData(&map, &tannu.key, &tannu);
    ASSERT(&tannu == getHashValue(&map, &ji.key));
}
void test_get_an_element_from_hashMap(){
    ASSERT(putHashData(&map, &tanbirka.key, &tanbirka.value));
    ASSERT(0 == strcmp((char*)getHashValue(&map, &tanbirka.key),tanbirka.value));
}

void test_get_NULL_when_key_is_not_present(){
    ASSERT(NULL == getHashValue(&map, &ji.key));
}
void test_get_NULL_when_map_is_null(){
    ASSERT(NULL == getHashValue(NULL,&tanbirka.key));

};
void test_getHashValue_gives_NULL_when_key_is_null(){
    ASSERT(NULL == getHashValue(&map,NULL));
};
void test_deletes_the_value_matched_to_given_key(){
    ASSERT(putHashData(&map,&ji.key , &ji));
    ASSERT(removeHashValue(&map, &ji.key));
    ASSERT(NULL == getHashValue(&map, &ji.key));        
}
void test_deletion_failed_when_key_is_not_present(){
    ASSERT(0 == removeHashValue(&map, &tanbirka.key));
    ASSERT(NULL == getHashValue(&map, &tanbirka.key));        
}
void test_deleting_element_which_is_not_present(){
    ASSERT(0 == removeHashValue(&map,&tanbirka));
};

void test_deleting_when_key_is_null_gives_NULL(){
    ASSERT(0 == removeHashValue(&map,NULL));

};
void test_deleting_when_map_is_null_gives_NULL(){
    ASSERT(0 == removeHashValue(NULL,NULL));
}

void test_iterating_over_hash_map(){
    Iterator it;
    putHashData(&map,&tanbirka.key,&tanbirka);
    putHashData(&map,&ji.key,&ji);
    it = getAllKeys(map);
    ASSERT(ji.key == *(int*)it.next(&it));
    ASSERT(tanbirka.key == *(int*)it.next(&it));
    ASSERT(NULL == it.next(&it));
};

